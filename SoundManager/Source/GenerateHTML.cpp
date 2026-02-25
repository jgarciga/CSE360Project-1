#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::ifstream xml("cppunit_results.xml");
    if (!xml.is_open()) {
        std::cerr << "Cannot open cppunit_results.xml\n";
        return 1;
    }

    std::ofstream html("TestReport.html");
    html << "<html><head><title>CppUnit Test Report</title></head><body>\n";
    html << "<h1>CppUnit Test Report</h1>\n";

    int totalTests = 0, totalFailures = 0, totalErrors = 0;

    // Read statistics first
    std::string line;
    while (std::getline(xml, line)) {
        if (line.find("<Tests>") != std::string::npos) {
            size_t start = line.find("<Tests>") + 7;
            size_t end = line.find("</Tests>");
            totalTests = std::stoi(line.substr(start, end - start));
        } else if (line.find("<FailuresTotal>") != std::string::npos) {
            size_t start = line.find("<FailuresTotal>") + 15;
            size_t end = line.find("</FailuresTotal>");
            totalFailures = std::stoi(line.substr(start, end - start));
        } else if (line.find("<Errors>") != std::string::npos) {
            size_t start = line.find("<Errors>") + 8;
            size_t end = line.find("</Errors>");
            totalErrors = std::stoi(line.substr(start, end - start));
        }
    }

    // Reset to beginning to read tests
    xml.clear();
    xml.seekg(0);

    html << "<h2>Summary</h2>\n";
    html << "<ul>\n";
    html << "<li>Total Tests: " << totalTests << "</li>\n";
    html << "<li>Failures: " << totalFailures << "</li>\n";
    html << "<li>Errors: " << totalErrors << "</li>\n";
    html << "</ul>\n";

    html << "<h2>Tests</h2>\n<ul>\n";

    while (std::getline(xml, line)) {
        if (line.find("<Name>") != std::string::npos) {
            size_t start = line.find("<Name>") + 6;
            size_t end = line.find("</Name>");
            std::string testName = line.substr(start, end - start);

            // Check if test is in FailedTests section
            bool failed = false;

            // Simple check: see if the next lines contain the name under <FailedTests>
            std::streampos pos = xml.tellg();
            std::string temp;
            while (std::getline(xml, temp) && temp.find("</FailedTests>") == std::string::npos) {
                if (temp.find(testName) != std::string::npos) {
                    failed = true;
                    break;
                }
            }
            xml.seekg(pos); // reset position for next test

            html << "<li>" << testName << " - " 
                 << (failed ? "<span style='color:red'>FAIL</span>" 
                            : "<span style='color:green'>PASS</span>") 
                 << "</li>\n";
        }
    }

    html << "</ul>\n</body></html>\n";
    std::cout << "HTML report generated: TestReport.html\n";
    return 0;
}