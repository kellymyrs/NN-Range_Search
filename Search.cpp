#include "Search.h"

void Range(vector<int>& c,unordered_map<int,vector <Item<int>*>>& hashtable,int& metric,double& R,int& M,int& probes,int& concat,vector<struct Item <int>*>& range){
	struct Item <int>* temp_item = NULL;
	double temp_dist;

	cout << "Range Search" << endl;

	//search bucket
	auto search = hashtable.find(concat);
	if(search != hashtable.end()){

		//cout << "Searching bucket" << endl;
		for (int i = 0; i < search->second.size(); i++){

			//cout << "Combining" << endl;
			temp_item = search->second[i];
			if(metric){
				temp_item->Cosine_Distance(c,temp_dist);
			}
			else{
				temp_item->Distance(c,temp_dist);
			}

			cout << "Temp Item coordinates : ";
			for (int j = 0; j < temp_item->coordinates.size() ; j++){
				cout << temp_item->coordinates[j] << " " ;
			 }
			cout << endl;

			cout <<"Found distance : "<< temp_dist << endl;

			if (temp_dist < R){
				int flag = 1;
				cout << "Adding an item to the range list" << endl;

				if(!range.empty()){ //avoid dublicates
					for( int j = 0 ; j < range.size() ; j++){
						if( range[j]->id == temp_item->id ){
							flag = 0;
						}
					}
				}
				
				if(flag){
					range.push_back(temp_item);
				}
			}
		}
	}
	else{
		cout << "Empty bucket" << endl;
		return;
	}

}


struct Item<int>* NN(vector<int>& c,unordered_map<int,vector <Item<int>*>>& hashtable,int& metric,int& M,int& probes,int& concat,double& min_dist){
	struct Item <int>* temp_item = NULL ,* min_item = NULL;
	double temp_dist;

	//search bucket
	auto search = hashtable.find(concat);
	if(search != hashtable.end()){

		//cout << "Searching bucket" << endl;
		for (int i = 0; i < search->second.size(); i++){

			//cout << "Combining" << endl;
			temp_item = search->second[i];
			if(metric){
				temp_item->Cosine_Distance(c,temp_dist);
			}
			else{
				temp_item->Distance(c,temp_dist);
			}
			

			//cout << "Temp Item coordinates : ";
			//for (int j = 0; j < temp_item->coordinates.size() ; j++){
			//	cout << temp_item->coordinates[j] << " " ;
			//}
			//cout << endl;

			//cout <<"Found distance : "<< temp_dist << endl;
			//cout <<"Min distance : "<< dist << endl;
			if (temp_dist < min_dist){
				//cout << "Change minimum" << endl;
				min_dist = temp_dist;
				min_item = temp_item;

				//cout << "Min Item coordinates : ";
				//for (int j = 0; j < min_item->coordinates.size() ; j++){
				//	cout << min_item->coordinates[j] << " " ;
				//}
				//cout << endl;
			}
		}
		return min_item;
	}
	else{
		cout << "Empty bucket" << endl;
		return NULL;
	}
}