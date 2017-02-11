﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace Adaptive.Schema.Net
{
    /// <summary>
    /// Base of Action types
    /// </summary>
    public class ActionBase : TypedElement
    {
        public ActionBase() { }

        /// <summary>
        /// Title of the action
        /// </summary>
        [JsonRequired]
        public string Title { get; set; } 
    }
}
