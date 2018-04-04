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
	void quicksort();
	void print();
	void Mergesort();
private:
	std::vector<int> L;
	
};
