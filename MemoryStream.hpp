#pragma once

#include <vector>

#include "Stream.hpp"

class MemoryStream : public Stream
{
public:
	MemoryStream();

	MemoryStream(int capacity);

	explicit MemoryStream(const std::vector<uint8_t>& buffer);

	~MemoryStream() override;

	int GetCapacity() const;

	void SetCapacity(int value);

	int GetLength() const;

	int GetPosition() const;

	void SetPosition(int value);

	int Read(uint8_t* buffer, int offset, int count) override;

	void Write(const uint8_t* buffer, int offset, int count) override;

	std::vector<uint8_t> ToArray() const;

private:
	bool EnsureCapacity(int value);

	const unsigned int MaxByteArrayLength = 0x7FFFFFC7;

	std::vector<uint8_t> buffer;
	int length;
	int capacity;
	int position;
	bool isOpen;
	bool isExpandable;
};
