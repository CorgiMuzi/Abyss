#pragma once

#include <windows.h>

namespace ch01::deadlock_example
{
    class CriticalSection
    {
    public:
        CriticalSection();
        ~CriticalSection();

        void Lock();
        void Unlock();

    private:
        CRITICAL_SECTION m_critSec;
    };

    class CriticalSectionLock
    {
        public:
        CriticalSectionLock(CriticalSection& critSec);
        ~CriticalSectionLock();

        private:
        CriticalSection* m_pCritSec;
    };

    int ExecMain();
}