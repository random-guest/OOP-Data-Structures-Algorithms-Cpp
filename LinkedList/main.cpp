#include <iostream>
#include<vector>
using namespace std;
struct item_node {
    int item_volume;
    item_node* item_next;
};
struct truck_node{
    truck_node* previous;
    truck_node* next;
    item_node* head;
    item_node* tail;
    int total_volume;
    int total_itemInTruck;
};
truck_node *addNewTruck(truck_node *pNode);
item_node *addNewItem(int value);
void SplitString(string s, vector<string> &v){

    string temp = "";
    for(int i=0;i<s.length();++i){

        if(s[i]==' '){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }

    }
    v.push_back(temp);

}
truck_node* initiateTruck(){
    truck_node *node = new truck_node();
    node->previous = NULL;
    node->next = NULL;
    node->head = NULL;
    node->tail = node->head;
    node->total_volume = 0;
    node->total_itemInTruck = 0;

    return node;
}
void addItem(truck_node*& head,truck_node*& tail,int value, int &NumberOfTrucks){
    if (value > 500){
        cout << "An item with a volume of more than 500 units cannot loaded to any truck.";
    }
    else{
        truck_node* cursor = head;
        while (cursor != NULL && (cursor->total_itemInTruck == 8 || (cursor->total_volume + value) > 500)){
            cursor = cursor->next;
        }
        if(cursor == NULL){
            cursor = addNewTruck(tail);
            if(tail->next == NULL){
                tail->next = cursor;
            }
            tail = cursor;
            NumberOfTrucks++;
        }
        item_node *item = addNewItem(value);
        if(cursor->head == NULL && cursor->tail == NULL){
            cursor->head = item;
            cursor->tail = item;
        }
        else{
            cursor->tail->item_next = item;
            cursor->tail = cursor->tail->item_next;
        }
        cursor->total_itemInTruck++;
        cursor->total_volume += value;
    }
}
void removeItem(truck_node* head, truck_node*& tail, int numberOfTruck, int truckPosition, int itemPosition){
    truck_node* cursor;
    int movements;
    int i = 0;
    if((numberOfTruck - truckPosition) >= (numberOfTruck / 2) ){
        cursor = head;
        movements = truckPosition;
        while ( i < (movements - 1)){
            cursor = cursor->next;
            i++;
        }
    }
    else{
        cursor = tail;
        movements = numberOfTruck - truckPosition;
        while ( i < (movements - 1)){
            cursor = cursor->previous;
            i++;
        }
    }
    item_node* currentItem = cursor->head;
    item_node* toDelete;
    if(itemPosition == 1){
        toDelete = currentItem;
        cursor->head = toDelete->item_next;
    }
    else{
        for(int j = 0; j < itemPosition - 2; j++){
            currentItem = currentItem->item_next;
        }
        toDelete = currentItem->item_next;
        currentItem->item_next = toDelete->item_next;
    }
    if(cursor->tail == toDelete){
        item_node* current = cursor->head;
        if( current == NULL){
            if(cursor->previous != NULL){
                cursor->previous->next = cursor->next;
            }
            if(cursor->next != NULL){
                cursor->next->previous = cursor->previous;
            }
            if(tail == cursor){
                tail = cursor->previous;
            }
        }
        else{
            while(current->item_next != NULL){
                current = current->item_next;
            }
            cursor->tail = current;
        }
    }
    cursor->total_itemInTruck--;
    cursor->total_volume -= toDelete->item_volume;
}
void truckDepart(truck_node*& head, truck_node*& tail, int &numberOfTrucks){
    int numberOfDeparturedTruckes = 0;
    truck_node* current = head;
    while(current != NULL){
        if(current->total_itemInTruck == 8 || current->total_volume >= 450){
            if(current == head){
                head = current->next;
                current->next->previous = NULL;
            }
            else{
                if(current->next != NULL){
                    current->next->previous = current->previous;
                }
                if(current->previous != NULL){
                    current->previous->next = current->next;
                }
            }
            if(current == tail){
                tail = current->previous;
            }
            numberOfDeparturedTruckes++;
            numberOfTrucks--;
        }
        current = current->next;
    }
    cout << numberOfDeparturedTruckes << " of trucks were departed" << std::endl;
}
void printDetailedSummary(truck_node* head, int numberOfTrucks){
    truck_node* currentTruck = head;
    int truckIndex = 1;
    while(currentTruck != NULL){
        string summary = "Cargo truck " + to_string(truckIndex) + " with " +
                         to_string(currentTruck->total_itemInTruck) + " item -> ";
        item_node* currentItem = currentTruck->head;
        int itemIndex = 1;
        while(currentItem != NULL){
            summary += to_string(currentItem->item_volume) + "(" + to_string(itemIndex) + ")";
            if(currentItem->item_next != NULL){
                summary += " + ";
            }
            currentItem = currentItem->item_next;
            itemIndex++;
        }
        summary += " = " + to_string(currentTruck->total_volume);
        cout << summary << endl;
        currentTruck = currentTruck->next;
        truckIndex++;
    }
}
void printSummaryReport(truck_node* head, int numberOfTrucks){
    truck_node* currentTruck = head;
    int truckIndex = 1;
    int totalVolume = 0;
    string summary = "Summary: ";
    while(currentTruck != NULL){
        summary += "Truck" + to_string(truckIndex) + "(" +
                to_string(currentTruck->total_volume) + ")";
        if(currentTruck->next != NULL){
            summary += " + ";
        }
        totalVolume += currentTruck->total_volume;
        currentTruck = currentTruck->next;
        truckIndex++;
    }
    summary += " = " + to_string(totalVolume);
    cout << summary << endl;
}
item_node *addNewItem(int value) {
    item_node *node = new item_node();
    node->item_next = NULL;
    node->item_volume = value;

    return node;
}
truck_node *addNewTruck(truck_node *pNode) {
    truck_node* node = initiateTruck();
    node->previous = pNode;

    return node;
}
int main() {
    truck_node* head = initiateTruck();
    truck_node* tail = head;
    int numberOfTrucks = 1;

    string operation;
    getline(cin, operation);
    while(operation!= "q")
    {
        vector<string> v;
        SplitString(operation, v);
        if(v[0]=="ai"){
            if(v.size() == 2){
                addItem(head,tail,std::stoi(v[1]),numberOfTrucks);
            }
        }
        if(v[0]=="ri"){
            if(v.size() == 3){
                removeItem(head, tail, numberOfTrucks, std::stoi(v[1]), std::stoi(v[2]));
            }
        }
        if(v[0]=="depart"){
            truckDepart(head, tail, numberOfTrucks);
        }
        if(v[0]=="rd"){
            printDetailedSummary(head, numberOfTrucks);
        }
        if(v[0]=="rs"){
            printSummaryReport(head, numberOfTrucks);
        }
        getline(cin, operation);
    }

    cout << "Quited";
    return 0;
}

