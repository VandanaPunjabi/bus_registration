#include<bits/stdc++.h>
using namespace std;


class Bus{
	string bus_no;
	string bus_driver;
	string bus_arr;
	string bus_depa;
	string b_from;
	string b_to;
	string bus_seat[8][4];
	
	public:
		void addNewBus();
		void makeRese(Bus buses[], int busInd);
		void clearSeat();
		void viewBusDetails();
		void showAB(Bus buses[]);
		void showSA(int busind);
		void displayLine(char ch);
};

void Bus :: addNewBus(){
	cout<<"Enter Bus Number"<<endl;
	cin>>bus_no;
	
	cout<<"Enter Drivers Name"<<endl;
	cin>>bus_driver;
	
	cout<<"Arrival Time"<<endl;
	cin>>bus_arr;
	
	cout<<"Departure Time"<<endl;
	cin>>bus_depa;
	
	cout<<"From: "<<endl;
	cin>>b_from;
	
	cout<<"To: "<<endl;
	cin>>b_to;
	
	clearSeat();
	cout<<"new Bus Added successfully"<<endl;
}

void Bus::makeRese(Bus buses[], int busInd){
	showSA(busInd);
	
	cout<<"Enter seat no for reservation"<<endl;
	int seatno;
	cin>>seatno;
	
	if(seatno < 1 || seatno > 32){
		cout<<"invalid seat no . please enter btw 1 to 32"<<endl;
		return;
	}
	
	int row = (seatno - 1) / 4;
	int col = (seatno - 1 ) % 4;
	
	if(buses[busInd].bus_seat[row][col] == "Empty"){
		cout<<"enter passenger names"<<endl;
		cin>>buses[busInd].bus_seat[row][col];
		cout<<"Reservation successful"<<endl;
	}
	else{
		cout<<"the seat is already reserved. please choose another seat"<<endl;
	}
	
}

void Bus::clearSeat(){
	for(int x = 0; x<8 ;x++){
		for(int z = 0; z<4; z++){
			bus_seat[x][z] = "empty";
		}
	}
}

void Bus::viewBusDetails(){
	displayLine('*');
	cout<<"Bus Number"<<bus_no<<endl;
	cout<<"Driver"<<bus_driver<<endl;
	cout<<"arrival Time" <<bus_arr<<endl;
	cout<<"Departure time"<<bus_depa<<endl;
	cout<<"From:"<<b_from<<endl;
	cout<<"To: "<<b_to<<endl;
	
	showSA(0);
}

void Bus::showAB(Bus buses[]){
	displayLine('*');
	cout<<"Available buses"<<endl;
	for(int i=0;i<5;i++){
		if(!buses[i].bus_no.empty()){
			cout<<"Bus number"<<buses[i].bus_no<<"\tDriver: "<<buses[i].bus_driver
			<<"\tFrom:"<<buses[i].b_from<<"]tTo:"<<buses[i].b_to<<endl;
			
		}
	}
	displayLine('_');
}

void Bus::showSA(int busIndex) {
    cout << "Seat Availability:\n";
    int seatNumber = 1;
 
    for (int x = 0; x < 8; x++) {
        for (int z = 0; z < 4; z++) {
            cout << setw(5) << left << seatNumber << ".";
            cout << setw(10) << left << bus_seat[x][z];
            seatNumber++;
        }
        cout << "\n";
    }
 
    cout << "\nThere are " << (32 - seatNumber + 1) << " Seats Available in Bus Number: " << bus_no << "\n";
}
void Bus::displayLine(char ch){
	for(int x=80;x>0;x--){
		cout<<ch<<" ";
	}
	cout<<endl;
}
int main(){
	const int MAX_BUSES = 5;
	Bus buses[MAX_BUSES];
	
	int ch;
	
	while(true){
		cout<<"\n\n";
		cout<<"BUS RESERVATION"<<endl;
		cout<<"\n\n";
		cout<<"\t\t\t1.Add New Bus\n\t\t\t"
		<<"2.Make Reservation\n\t\t\t"
		<<"3.View Reservation\n\t\t\t"
		<<"4.Show Availability\n\t\t\t"
		<<"5.Exit";
	cout<<"\n\t\t\Enter Your Choice";
	cin>>ch;
	
	switch(ch){
		case 1:
			buses[0].addNewBus();
			break;
		case 2:
			int busInd;
			cout<<"enter bus index:"<<endl;
			cin>>busInd;
			if(busInd>=0 && busInd < MAX_BUSES){
				buses[0].makeRese(buses,busInd);
			}
			else{
				cout<<"Invalid Bus Index"<<endl;
			}
			break;
		case 3:
			buses[0].viewBusDetails();
			break;
		case 4:
			buses[0].showAB(buses);
			break;
		case 5:
			cout<<"Exisiting the program. "<<endl;
			return 0;
		default:
			cout<<"Invalid choice. try again"<<endl;
	}
	}
	
	return 0;
}

