#include <iostream>
#include <iomanip>
#include <ctime>
#include "BackUp.h"
#include "BackUpModel.h"
#include "RemoveAmountAlg.h"
#include "RemoveDateAlg.h"
#include "RemoveSizeAlg.h"
#include "IRemove.h"
#include "RemoveHybridAlg.h"
#include <chrono>
#include "SaveManager.h"
#include "SaveJoin.h"
#include "SaveJoin.h"
#include "ISave.h"

int main() {
    
    try { 
        BackUpModel* currModel = new BackUpModel();
        BackUp* simpleBackUp = new BackUp();

        simpleBackUp->addFilesToBackUp(std::make_pair(std::string_view ("kek"), false)); // second arg defines that file isn't in some Restore Point (this file is new)
        simpleBackUp->addFilesToBackUp(std::make_pair(std::string_view ("lol"), false));
        simpleBackUp->addFilesToBackUp(std::make_pair(std::string_view ("tik"), false));
        simpleBackUp->addFilesToBackUp(std::make_pair(std::string_view ("tok"), false));
        
        simpleBackUp->createRestPoint(false); // increment or not

        simpleBackUp->addFilesToBackUp(std::make_pair(std::string_view ("mem"), false));

        simpleBackUp->createRestPoint(false); // increment or not

        SaveManager* currManager = new SaveManager();
        ISave* currSaveAlg = new SaveJoin();
        currManager->saveAs(simpleBackUp, currSaveAlg);
        
        
        

       /*[Tested]*/ 

        IRemove* currAmountRemAlg = new RemoveAmountAlg(/* cntLimit ==*/ 1);
        std::size_t restorePointCnt = currAmountRemAlg->getDiff(*(simpleBackUp)); // getting cnt of removed Restore Points
        simpleBackUp->removeUnSuitablePoints(restorePointCnt);
        
        /*[Tested]*/
        // time_t time = std::time(nullptr) + 3;
        // IRemove* currDateRemAlg = new RemoveDateAlg(time);
        // std::size_t restorePointCnt = currAmountRemAlg->getDiff(*(simpleBackUp));
        // simpleBackUp->removeUnSuitablePoints(restorePointCnt);
    
        /*[Tested]*/
        // IRemove* currSizeRemAlg = new RemoveSizeAlg(std::size_t(26));
        // std::size_t restorePointCnt = currAmountRemAlg->getDiff(*(simpleBackUp));
        // simpleBackUp->removeUnSuitablePoints(restorePointCnt);
    
        /*[Tested]*/
        // std::vector <IRemove*> givenHybridAlgs;
        // IRemove* currSizeRemAlg = new RemoveSizeAlg(std::size_t(25));
        // IRemove* currAmountRemAlg = new RemoveAmountAlg(/* cntLimit ==*/ 2);

        // givenHybridAlgs.push_back(currSizeRemAlg);
        // givenHybridAlgs.push_back(currAmountRemAlg);

        // IRemove* currHybridRemAlg = new RemoveHybridAlg(givenHybridAlgs, true);
        // std::size_t restorePointCnt = currAmountRemAlg->getDiff(*(simpleBackUp));
        // simpleBackUp->removeUnSuitablePoints(restorePointCnt);

        // std::cout << simpleBackUp->getRestPointCnt();


        
        
    } 
    catch(std::exception& exp) {
        std::cout << exp.what() << '\n';
    }

}