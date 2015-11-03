// ClrProfiler.h : CClrProfiler ������

#pragma once
#include "resource.h"       // ������



#include "BeyondAPMProfiler_i.h"
#include "ProfileBase.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CClrProfiler

class ATL_NO_VTABLE CClrProfiler :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CClrProfiler, &CLSID_ClrProfiler>,
	//public IDispatchImpl<IClrProfiler, &IID_IClrProfiler, &LIBID_BeyondAPMProfilerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public CProfilerBase
{
public:
	CClrProfiler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CLRPROFILER)


BEGIN_COM_MAP(CClrProfiler)
	COM_INTERFACE_ENTRY(ICorProfilerCallback)
    COM_INTERFACE_ENTRY(ICorProfilerCallback2)
    COM_INTERFACE_ENTRY(ICorProfilerCallback3)
#ifndef _TOOLSETV71
    COM_INTERFACE_ENTRY(ICorProfilerCallback4)
    COM_INTERFACE_ENTRY(ICorProfilerCallback5)
#endif
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		 if (m_profilerInfo!=NULL) m_profilerInfo.Release();
        if (m_profilerInfo2!=NULL) m_profilerInfo2.Release();
        if (m_profilerInfo3!=NULL) m_profilerInfo3.Release();
#ifndef _TOOLSETV71
        if (m_profilerInfo4!=NULL) m_profilerInfo4.Release();
#endif
	}

public:
	CComQIPtr<ICorProfilerInfo> m_profilerInfo;
    CComQIPtr<ICorProfilerInfo2> m_profilerInfo2;
    CComQIPtr<ICorProfilerInfo3> m_profilerInfo3;
#ifndef _TOOLSETV71
    CComQIPtr<ICorProfilerInfo4> m_profilerInfo4;
#endif


};

OBJECT_ENTRY_AUTO(__uuidof(ClrProfiler), CClrProfiler)
