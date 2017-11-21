#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;
int main () {
    
    mt19937 randomGenerator(time(0));
    uniform_int_distribution<int> PlayerAttack (1,6);
    uniform_int_distribution<int> sankeHP (20,40);
    uniform_int_distribution<int> SankeAttack (1,6);
    
    int pATK = PlayerAttack(randomGenerator);
    int sATK = SankeAttack(randomGenerator);
    int sHP = sankeHP(randomGenerator); // Snake's Health Points
    int pHP = 20; //Player's Health Points
    int maxPHP = pHP;
    int P = 2;     // quantity of potions
    int mxP = 1;   // quantity of max potions
    int item;

    cout << "You're roasting a marshmellow when, outta nowhere..."<<endl;
    cout << "A WILD SNAKE JUST APPEARED!!!!!"<< endl;
    cout << "********************************" << endl;
    cout << endl;
    cout << "TIP: Anylize enemy with SANKEDEX[TM] first, it's HP value is unknown..." << endl; 
    cout << endl;
    cout << "********************************" << endl;
    cout << endl;
    int act; 
    int kill = 1;      // terminate switch thingy, kill assumes value 1 or 0
    
    int i=1;
    while (sHP>0 and pHP>0) {
       
        cout << "What will you do now? \n";
        cout << "1 -> FIGHT         2 -> ITEM \n";
        cout << "3 -> RUN           4 -> SANKEDEX \n";
        cout << endl;
        cin >> act;
        cout << endl;
        
        if (act == 1) {
            
            cout << "You attack with "<< pATK << " damage!";
        if (pATK == 6) {
            cout << " CRITICAL HIT!" << endl;
        } else if (pATK == 1) {
            cout << " It's not very effective..." << endl;
        } else {
            cout << " Normal attack damage." << endl;
            }
        cout << endl;
            
        sHP = sHP - pATK;
        
        pATK = PlayerAttack(randomGenerator); 
        
            cout << "Snake attacks with " << sATK << " damage!";
        if (sATK == 6) {
            cout << " CRITICAL HIT!" << endl;
        } else if (sATK == 1) {
            cout << " It's not very effective..." << endl;
        } else {
            cout << " Normal attack damage." << endl; 
        }
        cout << endl;
        
        pHP = pHP - sATK;
        
        sATK = SankeAttack(randomGenerator);
        
        if  (sHP > 0) {
        cout << "Snake now has " << sHP << " HP left!" << endl;
        } else {
            cout << "Sanke now has 0 HP left!"<< endl;
            sHP = -1;
            }
        cout << endl;    
        if (pHP > 0) {
        cout << "You now have " << pHP << " HP left!" << endl;    
        } else {
            cout << "You now have 0 HP left!" << endl;
            pHP = -1;
            }
        cout << endl;
            
            
            
            i = i+1;
        }
            else if (act == 2) {
                
                kill = 1;
                while (P >= 0 and mxP >= 0 and kill==1) {
                
                cout << "You opened your ITEMS menu" << endl;
                cout << endl;
                cout << "1 -> POTION      (restores 5 HP)  --- " << P << endl;
                cout << "2 -> MAX POTION  (restores 10 HP) --- " << mxP << endl;
                cout << "3 -> Exit to ACTION menu" << endl;
                cout << endl;
                
                cin >> item;
                
                if (item == 1) { //player select to use potion
                    
                    if  (P > 0) {
                        cout << "You used a potion, HP replenised by 5!" << endl;   
                        
                        if (pHP < 15) {
                            
                            pHP = pHP + 5;
                            cout << "You now have " << pHP << " HP!" << endl;
                            
                        } else /* pHP >= 16 */ {
                            pHP = maxPHP;
                            cout << "You now have "<< maxPHP << " HP! Max HP value reached." << endl; 
                        }
                        P = P - 1;
                        
                    } 
                    else if (P == 0) {
                        cout << "No more POTIONs left..." << endl;
                    }
                    
                    
                    
                } else if (item == 2) { //player selects to use max potion
                    
                   if  (mxP > 0) {
                        cout << "You used a potion, HP replenised by 10!" << endl;   
                        
                        if (pHP < 10) {
                            
                            pHP = pHP + 10;
                            cout << "You now have " << pHP << " HP!" << endl;
                            
                        } else /* pHP >= 10 */ {
                            pHP = 20;
                            cout << "You now have 20 HP! Max HP value reached." << endl; 
                        }
                        mxP = mxP - 1; 
                   } else if (mxP == 0) {
                        cout << "No more MAX POTIONs left..." << endl;
                   }
                   
                } else if (item == 3) { //player selects to exit to action menu
                    kill = 0;
                    cout << endl;
                }
                
                
                } //end of while loop
                
                
            }
            else if (act == 3) { 
                cout << "You try to outrun the Snake, but it's too fast..." << endl;
                cout << "You're forced to return to the battlefield...stay strong, hero, you can do it!" << endl;
                cout << endl;
            }
            else if (act == 4) {
                
                cout << endl;
                cout << "You opened the one and only SANKEDEX[TM]!" << endl;
                cout << ".....anylizing......." << endl;
                cout << "Just your regular ol' rattle snake."<<endl;
                if (sHP>25) {
                cout << "Snake currently has "<< sHP <<" HP left." <<endl;
                cout << "It's a rather strong snake..."<< endl;
                } else if (sHP>15) {
                    cout << "Snake currently has "<< sHP <<" HP left." <<endl;
                    } else {
                          cout << "Snake currently has "<< sHP <<" HP left." <<endl;
                          cout << "It's weak! Go get 'em!"<<endl;
                        }
                cout << "You currently have "<< pHP << " HP left." << endl;
                cout << endl;
                
                }
       
  
        }
        
        cout << "********************************" << endl;
        cout << endl;
        
        if (sHP == -1) {
           cout << "Snake is dead after " << i-1 << " attacks!!! You won the battle!" << endl; 
        }
        if (pHP == -1) {
           cout << "You are dead after " << i-1 << " attacks... You lost the battle..." << endl;
        } //terminates fighting sequence and game over......
    
    return 0;
    
    }
