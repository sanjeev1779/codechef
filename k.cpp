#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

main()
{


	int T;
	cin>> T;

	for(int it = 1; it <= T; ++it)
	{
		int P, Q;
		cin>> P >> Q;

		vector<int> cells;
		cells.push_back(0);

		for(int i = 0; i < Q; ++i)
		{
			int c;
			cin>> c;
			cells.push_back(c);
		}

		cells.push_back(P + 1);

		int mat[128][128];
		memset(mat, 0, sizeof(mat));

		//cout << "Case " << it << endl;
		for(int d = 2; d < Q + 2; ++d)
		{
			for(int i = 0; i < Q + 2 - d; ++i)
			{
				int j = i + d;
				int bcost = 100000000;
				for(int k = i + 1; k < j; ++k)
				{
					bcost = min(bcost, mat[i][k] + mat[k][j] + cells[j] - cells[i] - 2);
				}
				mat[i][j] = bcost;
				//cout << i << ' ' << j << ": " << bcost << endl;
			}
		}

		cout<<mat[0][Q + 1]<<endl;
	}

	return 0;
}
