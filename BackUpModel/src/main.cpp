#include <iostream>
#include "backUpApp.h"


int main () {

        backUpApp app(1390);
        std::vector<std::string_view> docs;
        std::string_view doc1 = "tempFiles/kek.txt";
        std::string_view doc2 = "tempFiles/lol.txt";
        std::string_view doc3 = "tempFiles/txt.txt";
        std::string_view doc4 = "tempFiles/xD.txt";
        docs.push_back(doc1);
        docs.push_back(doc2);
        docs.push_back(doc3);
        docs.push_back(doc4);

    try{ 
        app.filesToBackUp(docs);
        app.createRestPoint("newFF");
        app.deleteFile("kek");
        app.createRestPoint("dd");
        app.addFile(doc2);
        app.createRestPoint("dd");
        app.saveRestPointAs("archive");
        app.controlRestorePointsAs("hybrid"); 
    } 
    catch(const std::runtime_error& exp){
        std::cout << exp.what() << "\n";
    }
}
