#include <iostream>
#include <iomanip>
#include <ctime>
#include "BackUp.h"
#include "BackUpModel.h"
#include "RemoveAmountAlg.h"
#include "RemoveDateAlg.h"
#include "RemoveSizeAlg.h"
#include "IRemoveManager.h"
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
        // IRemoveManager* currAmountRemAlg = new RemoveAmountAlg(/* cntLimit ==*/ 1);
        // simpleBackUp->removeUnSuitablePoints(currAmountRemAlg->getDiff(*(simpleBackUp)));
        
        /*[Tested]*/
        // time_t time = std::time(nullptr) + 3;
        // IRemoveManager* currDateRemAlg = new RemoveDateAlg(time);
        // simpleBackUp->removeUnSuitablePoints(currDateRemAlg->getDiff(*(simpleBackUp)));
    
        /*[Tested]*/
        // IRemoveManager* currSizeRemAlg = new RemoveSizeAlg(std::size_t(26));
        // simpleBackUp->removeUnSuitablePoints(currSizeRemAlg->getDiff(*(simpleBackUp)));
    
        /*[Tested]*/
        // std::vector <IRemoveManager*> givenHybridAlgs;
        // IRemoveManager* currSizeRemAlg = new RemoveSizeAlg(std::size_t(25));
        // IRemoveManager* currAmountRemAlg = new RemoveAmountAlg(/* cntLimit ==*/ 2);

        // givenHybridAlgs.push_back(currSizeRemAlg);
        // givenHybridAlgs.push_back(currAmountRemAlg);

        // IRemoveManager* currHybridRemAlg = new RemoveHybridAlg(givenHybridAlgs, true);
        // simpleBackUp->removeUnSuitablePoints(currHybridRemAlg->getDiff(*(simpleBackUp)));

        // std::cout << simpleBackUp->getRestPointCnt();


        
        
    } 
    catch(std::exception& exp) {
        std::cout << exp.what() << '\n';
    }

}