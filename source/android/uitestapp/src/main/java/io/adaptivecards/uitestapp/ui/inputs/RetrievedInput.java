package io.adaptivecards.uitestapp.ui.inputs;

import io.adaptivecards.uitestapp.ui.rendered_card.RenderedCardViewModel;

public class RetrievedInput
{
    private String m_id;
    private String m_value;

    public RetrievedInput(String id, String value)
    {
        m_id = id;
        m_value = value;
    }

    public String getId()
    {
        return m_id;
    }

    public String getValue()
    {
        return m_value;
    }
}
