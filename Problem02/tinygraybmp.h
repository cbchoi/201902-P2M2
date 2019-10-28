#pragma once
#pragma (push, 1)

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "tinybmp.h"

class tinygraybmp: public tinybmp
{
public:
	tinygraybmp(std::string file_name)
		:tinybmp(file_name), m_gray_buf(nullptr)
	{
		m_gray_buf = create_bitmap_8bit(m_bih.height, m_bih.width);

		for(int i = 0; i < m_bih.height; i++)
		{
			for(int j = 0; j < m_bih.width; j++)
			{
				m_gray_buf[i][j] = (  *(m_image_buf[(m_bih.height - 1 - i)] + (j*3+0))
								    + *(m_image_buf[(m_bih.height - 1 - i)] + (j*3+1))
								    + *(m_image_buf[(m_bih.height - 1 - i)] + (j*3+2)))/3;

			}
		}
	}

	virtual ~tinygraybmp()
	{
		if (m_gray_buf != nullptr)
		{
			for(int i = 0; i < m_bih.height; i++)
				delete[] m_gray_buf[i];
			
			delete[] m_gray_buf;
			m_gray_buf = nullptr;
		}
	}

public:
	unsigned char** get_image_buf(){ return m_gray_buf; }
	unsigned char** get_cloned_image_buf()
	{
		unsigned char** cloned = create_bitmap_8bit(m_bih.height, m_bih.width);
		std::memcpy(cloned, m_gray_buf, m_bih.height * m_bih.width);
		return cloned;
	}

public:
	unsigned char** create_bitmap_8bit(int height, int width)
	{
		unsigned char** image_buf;
		image_buf = new unsigned char*[height];
		for (int i = 0; i < height; i++)
		{
			image_buf[i] = new unsigned char[width];
		}
		return image_buf;
	}

	void export_image(std::string file_name)
	{
		for (int i = 0; i < m_bih.height; i++)
		{
			for (int j = 0; j < m_bih.width; j++)
			{
				*(m_image_buf[(m_bih.height - 1 - i)] + (j*3+0)) = m_gray_buf[i][j];
				*(m_image_buf[(m_bih.height - 1 - i)] + (j*3+1)) = m_gray_buf[i][j];
				*(m_image_buf[(m_bih.height - 1 - i)] + (j*3+2)) = m_gray_buf[i][j];
			}
		}
		tinybmp::export_image(file_name);
	}
protected:
	unsigned char** m_gray_buf;
};

#pragma (pop, 1)