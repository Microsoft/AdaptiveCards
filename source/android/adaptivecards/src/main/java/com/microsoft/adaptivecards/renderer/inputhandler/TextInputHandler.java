package com.microsoft.adaptivecards.renderer.inputhandler;

import android.graphics.Color;
import android.text.TextUtils;
import android.widget.EditText;

import com.microsoft.adaptivecards.objectmodel.BaseInputElement;

import java.text.ParseException;
import java.util.Map;

public class TextInputHandler extends BaseInputHandler
{
    public TextInputHandler(BaseInputElement baseInputElement)
    {
        super(baseInputElement);
    }

    protected EditText getEditText()
    {
        return (EditText) m_view;
    }

    @Override
    protected void setDefaultTextColor()
    {
        //TypedValue typedValue = new TypedValue();
        //m_editText.getContext().getTheme().resolveAttribute(android.R.attr.editTextColor, typedValue, true);
        //m_editText.setTextColor(typedValue.data);
        getEditText().setTextColor(Color.BLACK);
    }

    @Override
    protected void setInvalidTextColor()
    {
        getEditText().setTextColor(Color.RED);
    }

    @Override
    protected void internalValidate() throws ParseException {
        //Do nothing.
    }

    public Exception getData(Map<String, String> data)
    {

        data.put(m_baseInputElement.GetId(), getEditText().getText().toString());

        return null;
    }
}
