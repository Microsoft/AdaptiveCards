#include "stdafx.h"
#include <algorithm>
#include "ConsoleRender.h"
#include "TextBlock.h"
#include "Container.h"
#include "Image.h"
#include "ColumnSet.h"

using namespace AdaptiveSharedNamespace;
using namespace std::string_literals;

size_t RenderElements(std::vector<std::shared_ptr<BaseCardElement>> elements, size_t columnWidth, size_t x, size_t y, std::vector<std::string>& consoleString);
size_t RenderColumnSet(ColumnSet &set, size_t columnWidth, size_t x, size_t y, std::vector<std::string> &consoleString);
size_t RenderColumn(Column &set, size_t columnWidth, size_t x, size_t y, std::vector<std::string> &consoleString);

std::vector<std::string> ConvertToVector(const std::string &consoleString, size_t width)
{
	std::vector<std::string> vectorOut;
	vectorOut.reserve(consoleString.length() % width); // just a guess

	std::string currentLine;
	currentLine.reserve(width);
	for (auto currChar : consoleString)
	{
		if (currentLine.length() == 0 && isspace(currChar))
		{
			continue;
		}
		else
		{
			currentLine.push_back(currChar);
		}

		if (currentLine.length() >= width)
		{
			vectorOut.push_back(currentLine);
			currentLine.clear();
		}
	}
	vectorOut.push_back(currentLine);

	return vectorOut;
}

void EnsureRows(std::vector<std::string> &toEnsure, size_t cRows)
{
	while (toEnsure.size() < cRows)
	{
		toEnsure.push_back(""s);
	}
}

void WriteTextAtX(std::string &dest, std::string &src, size_t x)
{
	// dest.resize(????
	while (dest.size() < (x + src.size()))
	{
		dest.push_back(' ');
	}
	std::replace(src.begin(), src.end(), '\n', ' ');
	dest.replace(x, src.size(), src);
}

void CompositeVector(std::vector<std::string> &vectorDest, std::vector<std::string> &vectorIn, size_t x, size_t y)
{
	EnsureRows(vectorDest, y + vectorIn.size());
	for (size_t currRow = y; currRow < (vectorIn.size() + y); currRow++)
	{
		WriteTextAtX(vectorDest[currRow], vectorIn[currRow - y], x);
	}
}

size_t RenderElement(std::shared_ptr<BaseCardElement> element,  size_t columnWidth, size_t x, size_t &y, std::vector<std::string> &consoleString)
{
	size_t rowsRendered = 0;
	switch (element->GetElementType())
	{
	case CardElementType::Container:
		rowsRendered = RenderElements(std::dynamic_pointer_cast<Container>(element)->GetItems(), columnWidth, x, y, consoleString);
		break;
	case CardElementType::TextBlock:
	{
		auto textBlock = ConvertToVector(std::dynamic_pointer_cast<TextBlock>(element)->GetText(), columnWidth);
		CompositeVector(consoleString, textBlock, x, y);
		rowsRendered = textBlock.size();
		break;
	}
	case CardElementType::Image:
	{
		auto imageElem = std::dynamic_pointer_cast<Image>(element);
		std::string imageText = imageElem->GetAltText();
		imageText.append(" <" + imageElem->GetUrl() + ">");
		auto textBlock = ConvertToVector(imageText, columnWidth);
		CompositeVector(consoleString, textBlock, x, y);
		rowsRendered = textBlock.size();
		break;
	}
	case CardElementType::Column:
	{
		rowsRendered = RenderColumn(*std::dynamic_pointer_cast<Column>(element), columnWidth, x, y, consoleString);
		break;
	}
	case CardElementType::ColumnSet:
		rowsRendered = RenderColumnSet(*std::dynamic_pointer_cast<ColumnSet>(element), columnWidth, x, y, consoleString);
		break;
	default:
	{
		auto unimplText = ConvertToVector("Unimplemented: " + AdaptiveSharedNamespace::CardElementTypeToString(element->GetElementType()), columnWidth);
		CompositeVector(consoleString, unimplText, x, y);
		rowsRendered = unimplText.size();
		break;
	}
	}

	return rowsRendered;
}

size_t RenderElements(std::vector<std::shared_ptr<BaseCardElement>> elements,  size_t columnWidth, size_t x, size_t y, std::vector<std::string> &consoleString)
{
	for (auto element : elements)
	{
		y += RenderElement(element, columnWidth, x, y, consoleString);
	}
	return y;
}

size_t RenderColumn(Column &column, size_t columnWidth, size_t x, size_t y, std::vector<std::string> &consoleString)
{
	// first, build column
	std::vector<std::string> columnText;
	size_t columnY = 0;
	for (auto item : column.GetItems())
	{
		columnY += RenderElement(item, columnWidth, 0, columnY, columnText);
	}

	// composite column into place
	CompositeVector(consoleString, columnText, x, y);
	return columnY;
}

size_t RenderColumnSet(ColumnSet &set, size_t columnWidth, size_t x, size_t y, std::vector<std::string> &consoleString)
{
	auto columns = set.GetColumns();
	const auto cCols = columns.size();
	size_t maxY = 0;
	const size_t individualWidth = (columnWidth / cCols) - 3;

	for (size_t i = 0; i < cCols; i++)
	{
		maxY = std::max(maxY, RenderElement(columns[i], individualWidth, x + (i * individualWidth) + (i ? 1 : 0), y, consoleString));
	}
	return maxY;
}

#define ESC "\x1b"
void VTSaveCursor()
{
	printf(ESC "7");
}

void VTRestoreCursor()
{
	printf(ESC "8");
}
	
void VTSetCursorPos(size_t x, size_t y)
{
	printf(ESC "[%d;%dH", (unsigned int)y, (unsigned int)x);
}

void RenderAsColumn(const std::string &consoleString, size_t x, size_t y, size_t width)
{
	VTSaveCursor();

	VTSetCursorPos(x, y);
	size_t charsEmitted = 0;
	size_t currOffset = 0;
	for (char currChar : consoleString)
	{
		if (currChar == '\n')
		{
			charsEmitted = 0;
			currOffset += 2;
			VTSetCursorPos(x, y + currOffset);
		}
		else
		{
			if (charsEmitted == 0 && isspace(currChar))
			{
				continue;
			}
			putchar(currChar);
			charsEmitted++;
			if (charsEmitted >= width)
			{
				charsEmitted = 0;
				currOffset++;
				VTSetCursorPos(x, y + currOffset);
			}
		}
	}

	VTRestoreCursor();
}

#define LR_BORDER "\x1b(0x\x1b(B"

void RenderBorder(std::vector<std::string> &output, size_t columnWidth)
{
	std::string top;
	top.append(ESC "(0");
	top.append("l");
	for (unsigned int i = 0; i < columnWidth - 1; i++)
	{
		top.append("q");
	}
	top.append("k");
	top.append(ESC "(B");

	for (auto &row : output)
	{
		row.resize(columnWidth-1, ' ');
		row.insert(0, LR_BORDER);
		row.append(LR_BORDER);
	}

	std::string bottom;
	bottom.append(ESC "(0");
	bottom.append("m");
	for (unsigned int i = 0; i < columnWidth - 1; i++)
	{
		bottom.append("q");
	}
	bottom.append("j");
	bottom.append(ESC "(B");

	output[0] = top;
	//output.insert(output.begin(), top);
	output.push_back(bottom);
}

void RenderToConsole(std::shared_ptr<AdaptiveSharedNamespace::AdaptiveCard> card, size_t columnWidth, std::vector<std::string> &output)
{
	std::vector<std::string> outputVector;
	auto body = card->GetBody();
	RenderElements(body, columnWidth-4, 1, 1, output); // save 4 width for border
	RenderBorder(output, columnWidth);
	//printf("\n\n\n");

	//RenderAsColumn("Some sample text. Let's see how we do!\n Should be exciting."s, 10, 10, 10);
	//RenderAsColumn("More samples... This should be rendered to the right of.\n\n<-- That one."s, 21, 10, 10);

	//auto output = ConvertToVector("Some sample text. Let's see how we do!\n Should be exciting."s, 10);
	//auto output2 = ConvertToVector("More samples... This should be rendered to the right of.\n\n<-- That one."s, 10);
	
	/*CompositeVector(outputVector, output, 1, 1);
	CompositeVector(outputVector, output2, 12, 3);*/
}
