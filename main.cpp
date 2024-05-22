#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include "include/webui.hpp"


void startCount(webui::window::event* e) {
    // Initialize variables
    bool runTxtReset = true;
    std::string toWaitString = e->get_string();
    std::stringstream ss(toWaitString);
    int toWait;
    ss >> toWait;
    std::string JScode = "document.getElementById('timeText').innerHTML = 0;";
    // Initialize text
    e->get_window().run("document.getElementById('timeText').style.color = 'rgb(0, 97, 171)';");
    // Loop through the countdown
    for(int i = 0; i < toWait; i++) {
        // Reset the text
        if(runTxtReset) {
            e->get_window().run(JScode);
            runTxtReset = false;
            std::cout << "Text reset." << std::endl;
        }
        // Wait for 1 sec
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // Update the text
        JScode = "document.getElementById('timeText').innerHTML = " + std::to_string(i + 1) + ";";
        e->get_window().run(JScode);
        // Print how much time has passed
        std::cout << "Waited " << i + 1 << " seconds." << std::endl;
    }
    e->get_window().run("document.getElementById('timeText').style.color = 'rgb(0, 171, 6)';");
}

int main() {
    std::cout << "Start now." << std::endl;
    webui::window mainWindow;
    mainWindow.bind("count", startCount);
    mainWindow.show("web/index.html");
    webui::wait();
    return 0;
}