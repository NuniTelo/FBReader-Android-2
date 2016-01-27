/*
 * Copyright (C) 2004-2015 FBReader.ORG Limited <contact@fbreader.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __ZLOUTPUTSTREAM_H__
#define __ZLOUTPUTSTREAM_H__

#include <string>

class ZLOutputStream {

protected:
	ZLOutputStream();

public:
	virtual ~ZLOutputStream();
	virtual bool open() = 0;
	virtual void write(const char chr) = 0;
	virtual void write(const char *data, std::size_t len) = 0;
	void write(const std::string &str, std::size_t offset, std::size_t len);
	void write(const std::string &str);
	virtual void close() = 0;
	virtual bool hasErrors() = 0;

private:
	ZLOutputStream(const ZLOutputStream&);
	const ZLOutputStream &operator = (const ZLOutputStream&);
};

inline ZLOutputStream::ZLOutputStream() {}
inline ZLOutputStream::~ZLOutputStream() {}

inline void ZLOutputStream::write(const std::string &str) {
	write(str.data(), str.length());
}

inline void ZLOutputStream::write(const std::string &str, std::size_t offset, std::size_t len) {
	if (len > 0) {
		write(str.data() + offset, len);
	}
}

#endif /* __ZLOUTPUTSTREAM_H__ */
