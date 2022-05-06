// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Algorithms/DateTime.hpp>

#include <ctime>

#include <Platforms.hpp>

#include <sys/stat.h>

namespace Sa
{
	tm LocalTime(const time_t& _inTime)
	{
		tm qTime; // Queried time.

#if SA_WIN

		localtime_s(&qTime, &_inTime);

#else

		localtime_r(&_inTime, &qTime);

#endif

		return qTime;
	}


//{ Constructors

	DateTime::DateTime(uint8_t _second,
		uint8_t _minute,
		uint8_t _hour,
		uint8_t _day,
		uint8_t _month,
		uint16_t _year,
		uint8_t _weekday
	) noexcept :
		second{ _second },
		minute{ _minute },
		hour{ _hour },
		day{ _day },
		month{ _month },
		year{ _year },
		weekday{ _weekday }
	{
	}

	DateTime::DateTime(const tm& _time) noexcept :
		second{ static_cast<uint8_t>(_time.tm_sec) },
		minute{ static_cast<uint8_t>(_time.tm_min) },
		hour{ static_cast<uint8_t>(_time.tm_hour) },
		day{ static_cast<uint8_t>(_time.tm_mday) },
		month{ static_cast<uint8_t>(_time.tm_mon + 1) },		// January is month 1.
		year{ static_cast<uint16_t>(_time.tm_year + 1900) },	// tm_year is the year since 1900.
		weekday{ static_cast<uint8_t>(_time.tm_wday) }
	{
	}

//}


//{ Equals

	bool DateTime::Equals(const DateTime& _other) const noexcept
	{
		return second == _other.second &&
			minute == _other.minute &&
			hour == _other.hour &&
			day == _other.day &&
			month == _other.month &&
			year == _other.year &&
			weekday == _other.weekday;
	}

	bool DateTime::operator==(const DateTime& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	bool DateTime::operator!=(const DateTime& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}


	DateTime DateTime::Now() noexcept
	{
		return DateTime{ LocalTime(time(nullptr)) };
	}

	DateTime DateTime::GMNow() noexcept
	{
		tm qTime; // Queried time.
		const time_t currTime = time(nullptr);

#if SA_WIN
		gmtime_s(&qTime, &currTime);
#else
		gmtime_r(&currTime, &qTime);
#endif

		return DateTime{ qTime };
	}


	DateTime DateTime::FileStats(const std::string& _path)
	{
		struct stat backupStat;
		stat(_path.c_str(), &backupStat);

		return DateTime{ LocalTime(backupStat.st_mtime) };
	}


	std::string ToString(const DateTime& _date)
	{
		return std::to_string(_date.month) + '.' +
			std::to_string(_date.day) + '.' +
			std::to_string(_date.year) + '-' +
			std::to_string(_date.hour) + 'h' +
			std::to_string(_date.minute) + 'm' +
			std::to_string(_date.second) + 's';
	}
}
