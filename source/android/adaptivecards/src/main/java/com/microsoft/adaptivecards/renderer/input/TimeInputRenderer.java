package com.microsoft.adaptivecards.renderer.input;

import android.content.Context;
import android.os.Bundle;
import android.support.v4.app.FragmentManager;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

import com.microsoft.adaptivecards.renderer.inputhandler.IInputHandler;
import com.microsoft.adaptivecards.objectmodel.BaseCardElement;
import com.microsoft.adaptivecards.objectmodel.HostConfig;
import com.microsoft.adaptivecards.objectmodel.TimeInput;
import com.microsoft.adaptivecards.renderer.inputhandler.TimeInputHandler;

import java.util.Vector;

import static android.text.InputType.TYPE_NULL;

/**
 * Created by bekao on 6/25/2017.
 */

public class TimeInputRenderer extends TextInputRenderer
{
    private TimeInputRenderer()
    {
    }

    public static TimeInputRenderer getInstance()
    {
        if (s_instance == null)
        {
            s_instance = new TimeInputRenderer();
        }

        return s_instance;
    }

    @Override
    public View render(
            Context context,
            FragmentManager fragmentManager,
            ViewGroup viewGroup,
            BaseCardElement baseCardElement,
            Vector<IInputHandler> inputActionHandlerList,
            HostConfig hostConfig)
    {
        TimeInput timeInput = null;
        if (baseCardElement instanceof TimeInput)
        {
            timeInput = (TimeInput) baseCardElement;
        }
        else if ((timeInput = TimeInput.dynamic_cast(baseCardElement)) == null)
        {
            throw new InternalError("Unable to convert BaseCardElement to TimeInput object model.");
        }

        TimeInputHandler timeInputHandler = new TimeInputHandler(timeInput, fragmentManager);
        EditText editText = renderInternal(
                context,
                viewGroup,
                timeInput,
                timeInput.GetValue(),
                timeInput.GetPlaceholder(),
                timeInputHandler,
                inputActionHandlerList,
                hostConfig);
        editText.setRawInputType(TYPE_NULL);
        editText.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                TimeInputHandler timeInputHandler = (TimeInputHandler) v.getTag();
                TimeInput timeInput = (TimeInput) timeInputHandler.getBaseInputElement();
                TimePickerFragment timePickerFragment = new TimePickerFragment();
                timePickerFragment.initialize(timeInput, (EditText) v);
                Bundle args = new Bundle();
                args.putString("title", TITLE);
                timePickerFragment.setArguments(args);

                FragmentManager fm = timeInputHandler.getFragmentManager();
                timePickerFragment.show(fm, TITLE);

            }
        });

        setSpacingAndSeparator(context, viewGroup, timeInput.GetSpacing(), timeInput.GetSeparator(), hostConfig, true /* horizontal line */);
        return editText;
    }
    
    private static TimeInputRenderer s_instance = null;
    private static final String TITLE = "Set Time";
}
