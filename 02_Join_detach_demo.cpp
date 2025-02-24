#include<iostream>
#include<thread>

using namespace std;

void cleaning() {
    cout << "Started cleaning " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "Cleaning Completed" << this_thread::get_id() << endl;;
}

void fullspeed() {
    cout << "Speeding the ship" << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Speeding Completed" << this_thread::get_id() << endl;
}

void stop() {
    cout << "Stopping the ship" << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "The ship has been stopped" << this_thread::get_id() << endl;
}
int main()
{   
    int option;
    vector<thread> clean;
    while(1) {
        cout << "Enter 1 - Cleaning, 2 - Full Speed, 3 - Stop, 100 - Exit : " << endl;
        cin >>  option;
        switch(option) {
            case 1:   {
                    clean.emplace_back(thread(cleaning));
                    //clean.back().detach();
                    break;
            }
            case 2:  {
                    thread speed(fullspeed); 
                    speed.join();
                    break;
            }
            case 3:  {
                    thread stop1(stop); 
                    stop1.join();
                    break;
            }
            case 100:  
                for (int i =0 ; i < clean.size(); i++) {
                     if (clean[i].joinable()) {
                         clean[i].join();
                     }
                 }
                 cout << "Exiting the program" << endl;
                 return 0;
        }
    }
    return 0;
}