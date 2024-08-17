class Disjoint_Set{
	int n;
	vector<int>parents;
	vector<int>size;

  public:
	Disjoint_Set(int n){
		size.resize(n);
		fill(size.begin(),size.end(),1);
		parents.resize(n);
		for(int i = 0;i<n;i++){
			parents[i] = i;
		}
	}

	int get(int x){
		return parents[x] = (parents[x]==x?x:get(parents[x]));
	}

	void merge(int x, int y){
		int x_root = get(x);
		int y_root = get(y);

		if(x_root == y_root)return;
		if(size[x_root]<size[y_root]){
			swap(x_root,y_root);
		}
		size[x_root] += size[y_root];
		parents[y_root] = x_root; 
	}

	bool connected(int x, int y){
		return (get(x)==get(y));
	}

};