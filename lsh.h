struct Item {
	int id;
	vector<int> coordinates;
};

class Hashtable{
	private :
		unordered_map<Item*> hashtable;
}

class Lsh_Hashtable {
	private :
		vector<Hashtable*> lsh_hashtable;
}
		
vector<double>* hash_function_v(int d);