#include "pch.h"
#include "CollectionTypeElement.h"
#include "Util.h"

using namespace AdaptiveSharedNamespace;

CollectionTypeElement::CollectionTypeElement(ContainerStyle style, 
    VerticalContentAlignment alignment) : m_style(style), 
    m_verticalContentAlignment(alignment), m_hasPadding(false)
{
}

ContainerStyle CollectionTypeElement::GetStyle() const
{
    return m_style;
}

void CollectionTypeElement::SetStyle(const ContainerStyle value)
{
    m_style = value;
}

VerticalContentAlignment CollectionTypeElement::GetVerticalContentAlignment() const
{
    return m_verticalContentAlignment;
}

void CollectionTypeElement::SetVerticalContentAlignment(const VerticalContentAlignment value)
{
    m_verticalContentAlignment = value;
}

bool CollectionTypeElement::GetPadding() const
{
    return m_hasPadding;
}

void CollectionTypeElement::SetPadding(const bool value)
{
    m_hasPadding = value;
}

// Applies Padding Flag When appropriate
void CollectionTypeElement::ConfigPadding(ParseContext& context)
{
    // we set padding when parental style is different from child's, and its style should not be None
    SetPadding(GetStyle() != ContainerStyle::None && context.GetParentalContainerStyle() != GetStyle());
}
