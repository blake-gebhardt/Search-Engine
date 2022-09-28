//
// Created by Blake Gebhardt on 04.12.21.
//

#include "searcher.h"

searcher::searcher(docParser &in, queryProcessor &en) {
    back = in;
    searchBar = en;
}

void searcher::run(char *dataPath) {
    cout << "WELCOME TO GEBGLE." << endl;
    char entered = '7';
    fstream saver("persist.txt");
    while (entered != '6') {
        cout << "\nWHAT DO YOU WANT?" << endl;
        cout << " 1) Loading \n 2) Searching \n 3) Stats \n 4) Persisting \n 5) Clear \n 6) Quit \n >";
        cin >> entered;
        string query;

        switch (entered) {
            case '1' :
                cout << "Where from?" << endl;
                cout << " 1) Files \n 2) Persistence Index \n 3) Back \n >";
                cin >> entered;
                switch (entered) {
                    case '1':
                        cout << "Just a moment..";
                        back.accessEachFile(dataPath);

                        break;
                    case '2':
                        cout << "Persistence Index half supported\n";
                        back.readFromPers(saver);
                        break;
                    case '3':
                        break;
                }
                entered = '7';
                break;

            case '2' :
                cout << "What do you want to search?\n";
                //HERE WE'RE GONNA USE searchBar
                cin.ignore();
                getline(cin, query);
                searchBar.returnQuery(back, query);
                entered = '7';
                break;
            case '3' :
                cout << "Words Parsed: " << back.wordCounter << endl;
                cout << "Average Words per Doc: " << (back.wordCounter/306242) << endl;
                cout << "Organizations Logged: " << back.orgCounter << endl;
                cout << "People Logged: " << back.perCounter << endl;
                entered = '7';
                break;
            case '4' :
                cout << "Writing current index to file." << endl;
                back.printLevels(saver);
                entered = '7';
                break;
            case '5' :
                cout << "\n\n\n\n\n\n\n\n\n" << endl;
                entered = '7';
                break;
            case '6':
                cout << "Quitting...\n";
                cout << "See ya. Arrivederci. Au revoir. Auf Wiedersehen. До сведания.\n";
                break;
            default :
                cout << "Invalid option." << endl;
                entered = '7';
                break;
        }

    }


    saver.close();
}
