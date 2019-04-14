using System;
using System.Collections.Generic;
using System.Linq;

namespace AdaptiveCards
{
    static class ParseContext
    {
        public static void Initialize()
        {
            ElementIDs = new Dictionary<string, List<AdaptiveInternalID>>();
            IDStack = new Stack<Tuple<string, AdaptiveInternalID, bool>>();
        }

        private static IDictionary<string, List<AdaptiveInternalID>> ElementIDs = new Dictionary<string, List<AdaptiveInternalID>>();

        private static Stack<Tuple<string, AdaptiveInternalID, bool>> IDStack = new Stack<Tuple<string, AdaptiveInternalID, bool>>();

        // Push the provided state on to our ID stack
        public static void PushElement(string idJsonProperty, AdaptiveInternalID internalId, bool isFallback = false)
        {
            if (internalId.Equals(AdaptiveInternalID.Invalid))
            {
                throw new AdaptiveSerializationException($"Attemping to push an element on to the stack with an invalid ID");
            }
            IDStack.Push(new Tuple<string, AdaptiveInternalID, bool>(idJsonProperty, internalId, isFallback));
        }

        // Pop the last id off our stack and perform validation 
        public static void PopElement()
        {
            // about to pop an element off the stack. perform collision list maintenance and detection.
            var idsToPop = IDStack.Peek();
            string elementID = idsToPop.Item1;
            AdaptiveInternalID elementInternalID = idsToPop.Item2;
            bool isFallback = idsToPop.Item3;

            if (!string.IsNullOrEmpty(elementID))
            {
                bool haveCollision = false;
                var nearestFallbackID = GetNearestFallbackID(elementInternalID);

                // Walk through the list of elements we've seen with this ID
                if (ElementIDs.ContainsKey(elementID))
                {
                    foreach (var entryFallBackID in ElementIDs[elementID])
                    {
                        // If the element we're about to pop is the fallback parent for this entry, then there's no collision
                        // (fallback content is allowed to have the same ID as its parent)
                        if (entryFallBackID.Equals(elementInternalID))
                        {
                            haveCollision = false;
                            break;
                        }

                        // The inverse of the above -- if this element's fallback parent is the entry we're looking at, there's
                        // no collision.
                        try
                        {
                            // -1 is the last item on the stack (the one we're about to pop)
                            // -2 is the parent of the last item on the stack
                            var previousInStack = IDStack.ElementAt(IDStack.Count - 2);

                            if (previousInStack.Item2.Equals(entryFallBackID))
                            {
                                // we're looking at a fallback entry for our parent
                                break;
                            }
                        }
                        catch (IndexOutOfRangeException)
                        {
                            // we're looking at a toplevel element
                        }

                        // if the element we're inspecting is fallback content, continue on to the next entry
                        if (isFallback)
                        {
                            continue;
                        }

                        // at this point, we may or may not have a collision depending on additional entries.
                        haveCollision = true;
                    }
                }

                if (haveCollision)
                {
                    throw new AdaptiveSerializationException("Collision detected for id '" + elementID + "'");
                }

                // no need to add an entry for this element if it's fallback (we'll add one when we parse it for non-fallback)
                if (!isFallback)
                {
                    try
                    {
                        ElementIDs[elementID].Add(nearestFallbackID);
                    }
                    catch (KeyNotFoundException)
                    {
                        ElementIDs[elementID] = new List<AdaptiveInternalID>() { nearestFallbackID };
                    }
                }
            }
            IDStack.Pop();
        }

        // Walk stack looking for first element to be marked fallback (which isn't the ID we're supposed to skip), then
        // return its internal ID. If none, return an invalid ID. (see comment above)
        public static AdaptiveInternalID GetNearestFallbackID(AdaptiveInternalID skipID)
        {
            foreach (var curElement in IDStack)
            {
                // if element is fallback
                if (curElement.Item3)
                {
                    if (curElement.Item2.Equals(skipID))
                    {
                        return curElement.Item2;
                    }
                }
            }
            var invalidID = new AdaptiveInternalID();
            return invalidID;
        }
    }
}
