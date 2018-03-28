#include<vector>
class sort_item
{
public:
	sort_item();
	sort_item(std::vector<int> P);
	void bubblesort();
	void selectsort();
	void Insertsort();
	void Shellsort();
	void heapsort();
	void print();
private:
	std::vector<int> L;
	
};
