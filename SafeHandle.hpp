#pragma once

#include <windows.h>

class SafeHandle
{
protected:
	SafeHandle(HANDLE invalidHandleValue, bool _ownsHandle)
		: handle(invalidHandleValue),
		  ownsHandle(_ownsHandle)
	{
	}

public:
	virtual ~SafeHandle() = default;

	virtual bool IsInvalid() = 0;

	HANDLE GetHandle() const
	{
		return handle;
	}

protected:
	void SetHandle(HANDLE _handle)
	{
		handle = _handle;
	}

	HANDLE handle;
	bool ownsHandle;
};

class SafeHandleZeroOrMinusOneIsInvalid : public SafeHandle
{
protected:
	explicit SafeHandleZeroOrMinusOneIsInvalid(bool ownsHandle)
		: SafeHandle(nullptr, ownsHandle)
	{
	}

public:
	bool IsInvalid() override
	{
		return handle == nullptr || handle == INVALID_HANDLE_VALUE;
	}
};
