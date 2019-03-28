#ifndef _ASSEMBLY_TREE_H_
#define _ASSEMBLY_TREE_H_

class CAssemblyNode;
template<> class CElementTraits<CComPtr<CAssemblyNode>> : public CElementTraitsBase<CComPtr<CAssemblyNode>>
{
public:
    typedef CAssemblyNode * INARGTYPE;
    typedef CAssemblyNode * OUTARGTYPE;
};

typedef ATL::CSimpleMap<CAtlString, CComPtr<CAssemblyNode>> CAssemblyMap;
typedef CAtlArray<CComPtr<CAssemblyNode>> CAssemblyList;
typedef ATL::CSimpleMap<CAssemblyNode *, HTREEITEM> CAssemblySet;

class CAssemblyNode : public IUnknown
{
public:
    // �������
    CAtlString szName;
    CAtlString szArch;
    CAtlString szLanguage;
    CAtlString szVersion;
    CAtlString szToken;
    // ѡ��״̬
    BOOL bCheck;
    CAssemblySet Parent;
    CAssemblyList Depend;
    CAssemblyList Package;
    CAssemblyList Component;

public:
    STDMETHOD(QueryInterface)(REFIID /*riid*/, void ** /*ppv*/) { return E_NOTIMPL; }
    STDMETHOD_(ULONG, AddRef)() { return ::InterlockedIncrement(&m_lRes); }
    STDMETHOD_(ULONG, Release)() { LONG cRef = ::InterlockedDecrement(&m_lRes); if (cRef <= 0) delete this; return cRef; }

private:
    LONG m_lRes;

public:
    CAssemblyNode() : m_lRes(0), bCheck(FALSE) {}
};

#endif // _ASSEMBLY_TREE_H_