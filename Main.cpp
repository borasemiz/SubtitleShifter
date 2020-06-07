#include <ostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "StrParser.h"
#include "TimeUtils.h"

std::ostream& operator<<(std::ostream& out, const SubtitleItem& sub)
{
	out << sub.getSubNo() << std::endl;
	out << TimeUtils::format(sub.getStartTime()) << "-->" << TimeUtils::format(sub.getEndTime()) << std::endl;
	out << sub.getText() << std::endl;
	out << std::endl;
	return out;
}

void ShiftSubtitleFile(const std::string& FileName, int ShiftAmount)
{
	SubtitleParserFactory ParserFactory(FileName);
	SubtitleParser* Parser = ParserFactory.getParser();

	const std::vector<SubtitleItem*> SubtitleEntries = Parser->getSubtitles();

	std::ofstream Output(FileName + ".shifted");

	for (SubtitleItem* Entry : SubtitleEntries) {
		Entry->setStartTime(Entry->getStartTime() < ShiftAmount ? 0 : Entry->getStartTime() + ShiftAmount);
		Entry->setEndTime(Entry->getEndTime() < ShiftAmount ? 0 : Entry->getEndTime() + ShiftAmount);
		Output << *Entry;
	}

	Output.close();

	delete Parser;
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cerr << "Not enough arguments. SubtitleShifter <subtitlefile.srt> <milliseconds>.";
		return -1;
	}

	ShiftSubtitleFile(argv[1], std::stoi(argv[2]));

	return 0;
}
