#include <iostream>
#include <vector>
using namespace std;

enum BLOCK
{
	LOAD,
	WALL,
	ENTRANCE,
	EXIT
};

void MapDraw(vector<vector<int>> v)
{
	for (vector<int>::size_type i = 0; i < v.size(); i++) 
	{
		for (vector<int>::size_type j = 0; j < v[i].size(); j++)
		{
			switch (v[i][j])
			{
			case LOAD:
				cout << "  ";
				break;
			case WALL:
				cout << "■";
				break;
			case ENTRANCE:
				cout << "○";
				break;
			case EXIT:
				cout << "◎";
				break;
			}
		}
		cout << endl;
	}
	//반복자를 사용해서 출력하는 코드????????????
	//vector<vector<int>>::iterator Dimensional_iter;
	//vector<int>::iterator iter;
	//for (Dimensional_iter = v.begin(); Dimensional_iter != v.end(); Dimensional_iter++)
	//{
	//	for (int i = .begin(); iter != v[Dimensional_iter].end(); iter++)
	//	{
	//		cout << *iter << " ";
	//	}
	//	cout << endl;
	//}
}

void main()
{
	//vector<vector<int>> v(SIZE, vector<int>(SIZE, 0));
	vector<vector<int>> map
	({
		vector<int>({1,1,1,1,1,1,1,1,1,1}),
		vector<int>({2,0,1,1,1,0,1,1,1,1}),
		vector<int>({1,0,0,0,1,0,0,0,0,1}),
		vector<int>({1,1,1,0,1,1,1,1,0,1}),
		vector<int>({1,0,0,0,0,0,1,1,0,1}),
		vector<int>({1,1,1,1,1,0,1,1,0,1}),
		vector<int>({1,0,0,1,1,0,0,0,0,1}),
		vector<int>({1,1,0,1,1,0,1,1,1,1}),
		vector<int>({1,0,0,0,0,0,0,0,0,3}),
		vector<int>({1,1,1,1,1,1,1,1,1,1}),		
	});
	MapDraw(map);
}