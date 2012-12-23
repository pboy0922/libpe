#pragma once

#include "PE/PEElement.h"

LIBPE_NAMESPACE_BEGIN

template <class T>
class PESectionT :
    public IPESectionT<T>,
    public PEElementT<T>
{
public:
    PESectionT() : m_pSectionHeader(NULL) {}
    virtual ~PESectionT() {}

    LIBPE_SINGLE_THREAD_OBJECT()
    DECLARE_PE_ELEMENT(void)

    void InnerSetSectionHeader(typename PETrait<T>::RawSectionHeader *pSectionHeader) { m_pSectionHeader = pSectionHeader; }

    virtual const char * LIBPE_CALLTYPE GetName();
    virtual error_t LIBPE_CALLTYPE GetRelocations();
    virtual error_t LIBPE_CALLTYPE GetLineNumbers();
    virtual uint32_t LIBPE_CALLTYPE GetCharacteristics();

    virtual error_t LIBPE_CALLTYPE SetName(const char *pName);

private:
    LibPERawSectionHeaderT(T) *m_pSectionHeader;
};

template <class T>
class PEOverlayT :
    public IPEOverlayT<T>,
    public PEElementT<T>
{
public:
    PEOverlayT() {}
    virtual ~PEOverlayT() {}

    LIBPE_SINGLE_THREAD_OBJECT()
    DECLARE_PE_ELEMENT(void)
};

typedef PESectionT<PE32>    PESection32;
typedef PEOverlayT<PE32>    PEOverlay32;

typedef PESectionT<PE64>    PESection64;
typedef PEOverlayT<PE64>    PEOverlay64;

LIBPE_NAMESPACE_END
