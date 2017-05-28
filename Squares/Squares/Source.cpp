#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<fstream>

using namespace std;

int main()
{

	int V[10][10], H[10][10];
	int num[10];
	int k, i, j;
	int n, m;
	char ch;

	int sayac1 = 0;
	int sayac2 = 0;

	fstream InputF("Input.txt", ios::in);
	fstream OutputF("Output.txt", ios::out);

	if (!InputF || !OutputF)
	{
		cout << "File can not be opened!" << endl;
		system("pause");
		exit(0);
	}

	InputF >> n;
	while (!InputF.eof()) {

		sayac1 = 0;
		InputF >> m;
		//initializing matrices Horizontal&Vertical
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				H[i][j] = 0;
				V[i][j] = 0;
			}

			num[i] = 0;
		}

		//Updating matrices according to input.txt file
		while (m > 0)
		{
			InputF >> ch;
			InputF >> i;
			InputF >> j;
			if (toupper(ch) == 'H')
			{
				H[i - 1][j - 1] = 1;
			}
			else if (toupper(ch) == 'V')
			{
				V[j - 1][i - 1] = 1;
			}
			m--;
		}

		int c = 0;
		//process of counting all possible squares
		for (k = 1; k < n; k++)
		{
			for (i = 0; i < n - k; i++)
			{
				for (j = 0; j < n - 1; j++) {

					num[c] = num[c] + sayac1 / (k*k);
					sayac1 = 0;

					for (int m = j; m < j + k; m++) 
					{
						if (H[i][m] == 1 && H[i + k][m] == 1)
						{
							for (int l = i; l < k + i; l++)
							{
								if (V[l][j] == 1 && V[l][j + k] == 1)
									sayac1++;
							}
						}
					}
				}//j
			}//i
			c++;
		}//k

		//process of printing results to output.txt file
		OutputF << "Problem# " << sayac2 + 1 << "\n\n";
		int flag = 0;
		for (i = 0; i < n; i++) {

			if (num[i] > 0) {
				OutputF << num[i] << " square (s) of size " << i + 1 << "\n";
				flag = 1;
			}
		}

		if (flag == 0) {
			OutputF << "No completed squares can be found.\n";
		}

		OutputF << "**********************************" << "\n\n";
		sayac2++;
		InputF >> n;
	}
	cout << "All possible squares were counted successfully. Please check output.txt file..."<<endl;

	OutputF.close();
	InputF.close();
	system("pause");
	return 0;
}