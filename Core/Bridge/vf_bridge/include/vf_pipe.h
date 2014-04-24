#pragma once

#include "vf_base.h"

#define VF_PIPE_DATASIZE 1024
#define VF_PIPE_PRTCSIZE 15

namespace vapula
{
	//全双工跨进程信道
	class VAPULA_API Pipe
	{
	public:
		Pipe();
		~Pipe();
	private:
		pcstr _Id;
		raw _Data;
		raw _Mapping;
		uint32 _Volume;
 		bool _IsServer;

	//物理实现
	private:
		bool _CreateMapping(uint32 vol);
		void _CloseMapping();
		bool _BeginUpdate();
		void _EndUpdate();
	
	//协议
	private:
		uint8 _GetFlag(uint32 offset);
		void _SetFlag(uint32 offset, uint8 value);
		uint32 _GetValue(uint32 offset);
		void _SetValue(uint32 offset, uint32 value);
		void _Write(raw data, uint32 len);
		raw _Read();

	//链路
	public: 
		//获取信道标识;
		pcstr GetPipeId();

		//获取数据容量
		int GetVolume();
		
		//检测信道是否关闭
		bool IsClose();

		//启动监听
		//可指定信道的数据容量
		bool Listen(uint32 vol = VF_PIPE_DATASIZE);

		//连接指定的信道
		bool Connect(pcstr pid);

		//关闭信道
		void Close();

	//应用
	public:
		//检查新消息
		bool HasNewData();

		//获取可读有效数据的大小
		uint32 GetReadSize();

		//写入数据
		void Write(pcstr data);

		//读取数据
		pcstr Read();
	};
}