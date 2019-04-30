// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
package io.adaptivecards.renderer;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;

import io.adaptivecards.objectmodel.ColorsConfig;
import io.adaptivecards.objectmodel.ContainerStyle;
import io.adaptivecards.objectmodel.ForegroundColor;
import io.adaptivecards.objectmodel.HostConfig;
import io.adaptivecards.objectmodel.Spacing;
import io.adaptivecards.objectmodel.SpacingConfig;

public abstract class BaseCardElementRenderer implements IBaseCardElementRenderer
{
    protected static long getSpacingSize(Spacing spacing, SpacingConfig defaultSpacingConfig)
    {
        long spacingSize = 0;
        if (spacing == Spacing.None)
        {
            return 0;
        }
        else if (spacing == Spacing.Default)
        {
            spacingSize = defaultSpacingConfig.getDefaultSpacing();
        }
        else if (spacing == Spacing.ExtraLarge)
        {
            spacingSize = defaultSpacingConfig.getExtraLargeSpacing();
        }
        else if (spacing == Spacing.Large)
        {
            spacingSize = defaultSpacingConfig.getLargeSpacing();
        }
        else if (spacing == Spacing.Medium)
        {
            spacingSize = defaultSpacingConfig.getMediumSpacing();
        }
        else if (spacing == Spacing.Small)
        {
            spacingSize = defaultSpacingConfig.getSmallSpacing();
        }
        else if (spacing == Spacing.Padding)
        {
            spacingSize = defaultSpacingConfig.getPaddingSpacing();
        }
        else
        {
            throw new IllegalArgumentException("Unknown spacing style: " + spacing.toString());
        }

        return (int) spacingSize;
    }

    protected static int getColor(String colorCode)
    {
        return android.graphics.Color.parseColor(colorCode);
    }

    protected static void setSpacingAndSeparator(Context context,
                                               ViewGroup viewGroup,
                                               Spacing spacing,
                                               boolean separator,
                                               HostConfig hostConfig,
                                               boolean horizontalLine,
                                               boolean isImageSet)
    {
        if (viewGroup.getChildCount() <= 0)
        {
            //Do not add space to the first element of a viewgroup
            return;
        }
        int spacingSize = Util.dpToPixels(context, getSpacingSize(spacing, hostConfig.GetSpacing()));
        int separatorThickness = Util.dpToPixels(context, hostConfig.GetSeparator().getLineThickness());
        int separatorColor = android.graphics.Color.parseColor(hostConfig.GetSeparator().getLineColor());

        View view = new ImageView(context);
        LinearLayout.LayoutParams params;
        if (separator && separatorThickness > 0)
        {
            view.setBackgroundColor(separatorColor);
            params = new LinearLayout.LayoutParams(
                    horizontalLine ? LinearLayout.LayoutParams.MATCH_PARENT : separatorThickness,
                    horizontalLine ? separatorThickness : LinearLayout.LayoutParams.MATCH_PARENT);
            params.setMargins(
                    horizontalLine ? 0 : spacingSize / 2 /* left */,
                    horizontalLine ? spacingSize / 2 : 0 /* top */,
                    horizontalLine ? 0 : spacingSize / 2 /* right */,
                    horizontalLine ? spacingSize / 2 : 0 /* bottom */);
        }
        else
        {
            // As ImageSets use HorizontalFlowLayout, assigning the spacing between images as MatchParent will make them
            // use more space than needed (making a second row of images to render below the space for the imageSet)
            params = new LinearLayout.LayoutParams(
                    horizontalLine ? LinearLayout.LayoutParams.MATCH_PARENT : spacingSize,
                    horizontalLine ? spacingSize : (isImageSet ? 0 : LinearLayout.LayoutParams.MATCH_PARENT));
        }
        view.setLayoutParams(params);
        viewGroup.addView(view);
    }

    protected static void setSpacingAndSeparator(
            Context context,
            ViewGroup viewGroup,
            Spacing spacing,
            boolean separator,
            HostConfig hostConfig,
            boolean horizontalLine)
    {
        setSpacingAndSeparator(context, viewGroup, spacing, separator, hostConfig, horizontalLine, false /* isImageSet */);
    }
}
