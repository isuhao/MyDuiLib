#pragma once
#include <tchar.h>
#include <vector>
#include <string>

namespace em_utility
{
#ifndef FILE_BEGIN
    #define FILE_BEGIN        0
#endif

#ifndef FILE_CURRENT
    #define FILE_CURRENT    1
#endif

#ifndef FILE_END
    #define FILE_END        2
#endif

//IO接口
class io_base
{
public:
	static const int NORMAL_SUCCESS = 0;
	static const int NORMAL_FAILED = -1;
    io_base() { }
    virtual ~io_base() { };
	virtual bool is_dir_exists(const TCHAR* p_dir) = 0;  //判断目录是否存在
	virtual int make_dir(const TCHAR* p_dir) = 0; //创建一个目录
	virtual bool is_file_exists(const TCHAR* p_name) = 0; //文件是否存在
    virtual int open(const TCHAR* p_name, bool b_readonly) = 0;			//打开一个存在的文件
    virtual int close() = 0;										//关闭文件
    // read / write, will change current position
	//return : 0 for success, -1 for failed
    virtual int read(void* p_buffer, unsigned int n_bytes_2_read, unsigned int* p_bytes_read) = 0;					//从当前位置读数据到缓冲区
    virtual int write(const void* p_buffer, unsigned int n_bytes_2_write, unsigned int* p_bytes_written) = 0;		//把缓冲区数据写入当前位置
    // seek
    virtual int seek(int n_distance, unsigned int n_move_mode) = 0;			//当前指针定位
    // creation / destruction
    virtual int create(const TCHAR* p_name) = 0;			//创建一个文件
	virtual int destroy() = 0;											//删除一个文件
    virtual int set_EOF() = 0;											//截断或增长文件
    virtual int get_position() = 0;									//取得当前位置
    virtual int get_size() = 0;											//取得文件大小
    virtual int get_name(TCHAR* p_buffer) = 0;				//取得文件名
	virtual bool is_open() = 0;										//是否打开
	virtual int flush() = 0;												//物理同步
};

//位置信息
struct pos_info
{
public:
	pos_info(unsigned int n_begin = 0, unsigned int n_len = 0);
	virtual ~pos_info();
	unsigned int get_begin() const;
	unsigned int get_len() const;
	unsigned int get_end() const;
	void set_info(unsigned int n_begin, unsigned int n_len);
	bool valid() const;
	unsigned int size() const;
	bool is_sub_pos(const pos_info& pos) const;
	bool is_equal_pos(const pos_info& pos) const;
private:
	unsigned int mn_begin;		//数据开始位置
	unsigned int mn_len;				//数据长度
};

typedef std::vector<pos_info> position_container;
typedef position_container::iterator position_iter;

}
