#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

int** preproccess(std::ifstream& fin, int& size_x, int& dimension)
{
	int** maps;

	std::string buf;
	std::getline(fin, buf);

	{
		std::istringstream iss(buf);
		std::vector<std::string> h_list(std::istream_iterator<std::string>{iss},
										std::istream_iterator<std::string>());

		size_x = std::stoi(h_list[0]);
		dimension = std::stoi(h_list[1]);
	}

	maps = new int*[dimension];
	for(int i = 0; i < dimension; i++)
	{
		maps[i] = new int[size_x];
		std::getline(fin, buf);
		std::istringstream iss(buf);
		std::vector<std::string> b_list(std::istream_iterator<std::string>{iss},
										std::istream_iterator<std::string>());

		int idx = 0;
		for(std::vector<std::string>::iterator iter = b_list.begin();
			iter != b_list.end();
			++iter)
		{
			maps[i][idx++] = std::stoi(*iter);
		}
	}
	return maps;
}

void postprocess(int** maps, int dimension)
{
	for(int i = 0; i < dimension; i++)
		delete [] maps[i];

	delete [] maps; 
}

void process(int** maps, int size_x, int dimension);

int main()
{
	int** maps;
	int dimension;
	int size_x;

	std::ifstream fin;
	fin.open("data.in");
	maps = preproccess(fin, size_x, dimension);
	process(maps, size_x, dimension);
	postprocess(maps, dimension);
	fin.close();
	return 0;
}

//////////// Problematic Region ////////////////////////////
void process(int** maps, int size_x, int dimension)
{
	int max_so_far = 0;
	int max_region_start = 0;
	int max_region_end = 0;

	int max_tail = 0;
	int max_tail_start = 0;
	int max_tail_end = 0;

	for(int i = 0; i < size_x; i++)
    {
    	// Update max_tail
    	// fill in the blanks
    	for(int j = 0; j < dimension; j++)
    		max_tail = max_tail + maps[j][i];

        if(max_tail < 0)
        {
  	    	// reset max tail's index
  	    	// reset max_tail value
  	    	// fill in the blanks
	       	max_tail_start = i+1;
        	max_tail_end = i+1;
        	max_tail = 0;
        }
        else
        {
        	// increase max_tail index
        	// fill in the blanks
            max_tail_end++;
        }

        if(max_so_far < max_tail)
        {
        	// 1. update max_so_far to max_tail
        	// 2. update max_region_start, max_region_end index
        	// fill in the blanks
            max_so_far = max_tail;
            max_region_start = max_tail_start;
            max_region_end = max_tail_end;
        }
    }  

    for(int i = 0; i < dimension; i++)
    {
    	for(int j = max_region_start; j < max_region_end; j++)
    	{
    		std::cout << maps[i][j] << " ";
    	}
    	std::cout << std::endl;
    }  
}
//////////// Problematic Region ////////////////////////////
