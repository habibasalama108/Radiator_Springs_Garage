#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//base class that contains the common information for all cars
class Car {
private:
    int carNumber;
    string fullName;
    int age;
    string type;
    string racingTeam;
    double speed;
    double capacity;

public:
    //setters to update car information
    void setCarNumber(int num){ carNumber = num; }
    void setFullName(string name){ fullName = name; }
    void setAge(int a){ if(a > 0) age = a; }
    void setType(string t){ type = t; }
    void setRacingTeam(string team){ racingTeam = team; }
    void setSpeed(double s){ if(s > 0) speed = s; }
    void setCapacity(double c){ if(c > 0) capacity = c; }
    
    //getters to access private data
    int getCarNumber(){ return carNumber; }
    string getFullName(){ return fullName; }
    int getAge(){ return age; }
    string getType(){ return type; }
    string getRacingTeam(){ return racingTeam; }
    double getSpeed(){ return speed; }
    double getCapacity(){ return capacity; }

    //display the common information for any car
    void displayBasicInfo(){
        cout << "Car Number: " << getCarNumber() << endl;
        cout << "Full Name: " << getFullName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Type: " << getType() << endl;
        cout << "Racing Team: " << getRacingTeam() << endl;
        cout << "Speed: " << getSpeed() << endl;
        cout << "Capacity: " << getCapacity() << endl;
    }
    
    //pure virtual functions that will be implemented in derived classes
    virtual double calculatePerformance() = 0;
    virtual void displayInfo() = 0;
    virtual void update() = 0;
    virtual void saveToFile(ofstream &out) = 0;
    virtual ~Car(){}
};

//Racer class inherits from car
class Racer : public Car{

private:

    int racesCompleted;
    int lapsCompleted;

public:

    void setRacesCompleted(int races){
        racesCompleted = races;
    }

    void setLapsCompleted(int laps){
        lapsCompleted = laps;
    }

    int getRacesCompleted(){
        return racesCompleted;
    }

    int getLapsCompleted(){
        return lapsCompleted;
    }

    //calculate racer performance score
    double calculatePerformance() override{
        return getSpeed()*10 + getCapacity();
    }

    // Display racer information
    void displayInfo() override{
        displayBasicInfo();
        cout << "Races Completed: " << racesCompleted << endl;
        cout << "Laps Completed: " << lapsCompleted << endl;
        cout << "Performance Score: " << calculatePerformance() << endl;
    }

    //update racer information
    void update() override{
        int age;
        string team;
        double speed;
        double capacity;
        int races;
        int laps;
        
        cout<<"New Age: ";
        cin>>age;
        cin.ignore();
        cout<<"New Racing Team: ";
        getline(cin,team);
        cout<<"New Speed: ";
        cin>>speed;
        cout<<"New Capacity: ";
        cin>>capacity;
        cout<<"New Races Completed: ";
        cin>>races;
        cout<<"New Laps Completed: ";
        cin>>laps;
        setAge(age);
        setRacingTeam(team);
        setSpeed(speed);
        setCapacity(capacity);
        setRacesCompleted(races);
        setLapsCompleted(laps);
    }

    //save racer data to the file
    void saveToFile(ofstream &out) override{
        out<<"Racer"<<endl;
        out<<getCarNumber()<<endl;
        out<<getFullName()<<endl;
        out<<getAge()<<endl;
        out<<getRacingTeam()<<endl;
        out<<getSpeed()<<endl;
        out<<getCapacity()<<endl;
        out<<getRacesCompleted()<<endl;
        out<<getLapsCompleted()<<endl;
    }
};

// support vehicle class inherits from car
class SupportVehicle : public Car{

private:

    int crewSize;
    double reliabilityRating;

public:

    void setCrewSize(int crew){
        crewSize = crew;
    }

    void setReliabilityRating(double rate){
        reliabilityRating = rate;
    }

    int getCrewSize(){
        return crewSize;
    }

    double getReliabilityRating(){
        return reliabilityRating;
    }

    //calculate support vehicle performance score
    double calculatePerformance() override{
        return (getSpeed()*5) + (getCapacity()*5);
    }

    //display support vehicle information
    void displayInfo() override{
        displayBasicInfo();
        cout << "Crew Size: " << crewSize << endl;
        cout << "Reliability Rating: " << reliabilityRating << endl;
        cout << "Performance Score: " << calculatePerformance() << endl;
    }

    //update support vehicle information
    void update() override{
        int age;
        string team;
        double speed;
        double capacity;
        int crew;
        double rate;

        cout<<"New Age: ";
        cin>>age;
        cin.ignore();
        cout<<"New Racing Team: ";
        getline(cin,team);
        cout<<"New Speed: ";
        cin>>speed;
        cout<<"New Capacity: ";
        cin>>capacity;
        cout<<"New Crew Size: ";
        cin>>crew;
        cout<<"New Reliability Rating: ";
        cin>>rate;
        setAge(age);
        setRacingTeam(team);
        setSpeed(speed);
        setCapacity(capacity);
        setCrewSize(crew);
        setReliabilityRating(rate);
    }

    // save support vehicle data to the file
    void saveToFile(ofstream &out) override{
        out<<"SupportVehicle"<<endl;
        out<<getCarNumber()<<endl;
        out<<getFullName()<<endl;
        out<<getAge()<<endl;
        out<<getRacingTeam()<<endl;
        out<<getSpeed()<<endl;
        out<<getCapacity()<<endl;
        out<<getCrewSize()<<endl;
        out<<getReliabilityRating()<<endl;
    }
}; 

//store all cars inside the garage
vector<Car*> garage;

//function prototype for saving data
void saveData();

//add a new car to the garage 
void checkIn(){

    int typeChoice;
    cout<<"\n1. Racer"<<endl;
    cout<<"2. Support Vehicle"<<endl;
    cout<<"Choose Type: ";
    cin>>typeChoice;

    if(typeChoice==1){

        Racer* car=new Racer();

        int number;
        string name;
        int age;
        string team;
        double speed;
        double capacity;
        int races;
        int laps;

        cout<<"Car Number: ";
        cin>>number;

        // check if the car number aleardy exists
        bool exists = false;

        for(int i = 0; i < garage.size(); i++){
            if(garage[i]->getCarNumber() == number){
                exists = true;
                break;
            }
        }

        if(exists){
            cout << "Car Number Already Exists!" << endl;
            delete car;
            return;
        }

        cin.ignore();
        cout<<"Full Name: ";
        getline(cin,name);
        cout<<"Age: ";
        cin>>age;
        cin.ignore();
        cout<<"Racing Team: ";
        getline(cin,team);
        cout<<"Speed: ";
        cin>>speed;
        cout<<"Capacity: ";
        cin>>capacity;
        cout<<"Races Completed: ";
        cin>>races;
        cout<<"Laps Completed: ";
        cin>>laps;

        car->setCarNumber(number);
        car->setFullName(name);
        car->setAge(age);
        car->setType("Racer");
        car->setRacingTeam(team);
        car->setSpeed(speed);
        car->setCapacity(capacity);
        car->setRacesCompleted(races);
        car->setLapsCompleted(laps);

        //add the new car to the garage
        garage.push_back(car);
        cout<<"\nCar Checked In Successfully!\n";
        saveData();
    }

    else if(typeChoice==2){

        SupportVehicle* car=new SupportVehicle();

        int number;
        string name;
        int age;
        string team;
        double speed;
        double capacity;
        int crew;
        double rate;

        cout<<"Car Number: ";
        cin>>number;

        // check if the car number aleardy exists
        bool exists = false;

        for(int i = 0; i < garage.size(); i++){
            if(garage[i]->getCarNumber() == number){
                exists = true;
                break;
            }
        }

        if(exists){
            cout << "Car Number Already Exists!" << endl;
            delete car;
            return;
        }
        
        cin.ignore();
        cout<<"Full Name: ";
        getline(cin,name);
        cout<<"Age: ";
        cin>>age;
        cin.ignore();
        cout<<"Racing Team: ";
        getline(cin,team);
        cout<<"Speed: ";
        cin>>speed;
        cout<<"Capacity: ";
        cin>>capacity;
        cout<<"Crew Size: ";
        cin>>crew;
        cout<<"Reliability Rating: ";
        cin>>rate;

        car->setCarNumber(number);
        car->setFullName(name);
        car->setAge(age);
        car->setType("Support Vehicle");
        car->setRacingTeam(team);
        car->setSpeed(speed);
        car->setCapacity(capacity);
        car->setCrewSize(crew);
        car->setReliabilityRating(rate);

        //add the new car to the garage
        garage.push_back(car);
        cout<<"\nCar Checked In Successfully!\n";
        saveData();
    }

    // if the user enter invalid type (is not exsit)
    else{
        cout<<"Invalid Type"<<endl;
    }
}

//Display all cars stored in the garage
void viewGarage(){
    if(garage.empty()){
        cout<<"\nGarage is Empty!\n";
        return;
    }

    cout<<"\n========== Garage ==========\n";

    for(int i=0;i<garage.size();i++){
        garage[i]->displayInfo();
        cout<<"---------------------------"<<endl;
    }
}

// search for a car by number or name
void findCar(){
    int choice;
    cout<<"\n1. Search by Car Number"<<endl;
    cout<<"2. Search by Name"<<endl;
    cout<<"Choose: ";
    cin>>choice;
    bool found=false;

    if(choice==1){
        int number;
        cout<<"Enter Car Number: ";
        cin>>number;

        for(int i=0;i<garage.size();i++){
            if(garage[i]->getCarNumber()==number){
                garage[i]->displayInfo();
                found=true;
            }
        }
    }

    else if(choice==2){
        string name;
        cin.ignore();
        cout<<"Enter Name: ";
        getline(cin,name);

        for(int i=0;i<garage.size();i++){
            if(garage[i]->getFullName()==name){
                garage[i]->displayInfo();
                found=true;
            }
        }
    }

    if(!found){
        cout<<"Car Not Found!"<<endl;
    }
}

//update the information of an existing car
void updateCar(){
    int number;
    bool found = false;
    cout << "Enter Car Number: ";
    cin >> number;

    for(int i = 0; i < garage.size(); i++){
        if(garage[i]->getCarNumber() == number){
            garage[i]->update();
            cout << "Car Updated Successfully!" << endl;
            saveData();
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Car Not Found!" << endl;
    }
}

// remove a car from the garage 
void retireCar(){
    int number;
    bool found = false;
    char choice;
    cout << "Enter Car Number: ";
    cin >> number;

    for(int i = 0; i < garage.size(); i++){
        if(garage[i]->getCarNumber() == number){
            cout << "Are you sure? (y/n): ";
            cin >> choice;

            if(choice == 'y' || choice == 'Y'){
                // free the memory before removing the object 
                delete garage[i];
                garage.erase(garage.begin() + i);
                cout << "Car Removed Successfully!" << endl;
                saveData();
            }
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Car Not Found!" << endl;
    }
}

//Display simple statistics about the garage 
void garageReport(){
    if(garage.empty()){
        cout<<"Garage is Empty!"<<endl;
        return;
    }

    double totalPerformance = 0;
    int racerCount = 0;
    int supportCount = 0;

    for(int i=0;i<garage.size();i++){
        totalPerformance += garage[i]->calculatePerformance();
        if(garage[i]->getType()=="Racer")
            racerCount++;
        else
            supportCount++;
    }

    cout<<"\n========== Garage Report ==========\n";

    cout<<"Total Cars: "<<garage.size()<<endl;
    cout<<"Average Performance: "
        << totalPerformance/garage.size() << endl;
    cout<<"Racers: "<<racerCount<<endl;
    cout<<"Support Vehicles: "<<supportCount<<endl;
}

// save all garage data into a text file
void saveData(){
    // open the file for writing
    ofstream file("garage.txt");
    if(!file.is_open()){
        return;
    }
    file<<garage.size()<<endl;
    for(int i=0;i<garage.size();i++){
        garage[i]->saveToFile(file);
    }
    file.close();
}

// load saved data from the text file 
void loadData(){
    //open the file for reading
    ifstream file("garage.txt");

    if(!file.is_open()){
        return;
    }
    
    int size;
    file >> size;

    for(int i = 0; i < size; i++){

        string type;
        file >> type;

        if(type == "Racer"){

            Racer* car = new Racer();
            int number, age, races, laps;
            string name, team;
            double speed, capacity;

            file >> number;
            file.ignore();
            getline(file, name);
            file >> age;
            file.ignore();
            getline(file, team);
            file >> speed;
            file >> capacity;
            file >> races;
            file >> laps;

            car->setCarNumber(number);
            car->setFullName(name);
            car->setAge(age);
            car->setType("Racer");
            car->setRacingTeam(team);
            car->setSpeed(speed);
            car->setCapacity(capacity);
            car->setRacesCompleted(races);
            car->setLapsCompleted(laps);
            garage.push_back(car);
        }

        else{

            SupportVehicle* car = new SupportVehicle();
            int number, age, crew;
            string name, team;
            double speed, capacity, rate;

            file >> number;
            file.ignore();
            getline(file, name);
            file >> age;
            file.ignore();
            getline(file, team);
            file >> speed;
            file >> capacity;
            file >> crew;
            file >> rate;

            car->setCarNumber(number);
            car->setFullName(name);
            car->setAge(age);
            car->setType("Support Vehicle");
            car->setRacingTeam(team);
            car->setSpeed(speed);
            car->setCapacity(capacity);
            car->setCrewSize(crew);
            car->setReliabilityRating(rate);
            garage.push_back(car);
        }
    }
    file.close();
}

// main function
int main(){

    //load previously saved cars
    loadData();

    int choice;

    // Display the main menu until the user chooses Exit
    do{

        cout<<"\n========== Radiator Springs Garage ==========\n";

        cout<<"1. Check In Car"<<endl;
        cout<<"2. View Garage"<<endl;
        cout<<"3. Tune Up"<<endl;
        cout<<"4. Retire Car"<<endl;
        cout<<"5. Find Car"<<endl;
        cout<<"6. Garage Report"<<endl;
        cout<<"7. Exit"<<endl;

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice){

        case 1:
            checkIn();
            break;

        case 2:
            viewGarage();
            break;

        case 3:
            updateCar();
            break;

        case 4:
            retireCar();
            break;

        case 5:
            findCar();
            break;

        case 6:
            garageReport();
            break;

        case 7:
            cout<<"Good Bye!"<<endl;
            break;

        default:
            cout<<"Invalid Choice!"<<endl;
        }
    }while(choice!=7);

    //release allocated memory before exiting
    for(int i = 0; i < garage.size(); i++){
        delete garage[i];
    }
    return 0;
}