// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma	once

#ifndef SAPPHIRE_SUPPORT_DATE_TIME_GUARD
#define SAPPHIRE_SUPPORT_DATE_TIME_GUARD

#include <cstdint>

#include <string>

namespace Sa
{
	struct DateTime
	{
		/// second number [0, 59].
		uint8_t second = 0;

		/// minute number [0, 59].
		uint8_t minute = 0;

		/// hour number [0, 23].
		uint8_t hour = 0;

		/// day of the month number [1, 31].
		uint8_t day = 0;

		/// month number [1, 12].
		uint8_t month = 0;

		/// Year number.
		uint16_t year = 0;

		/// day number of the week [0, 6].
		uint8_t weekday = 0;


//{ Constructors

		/// Default constructor.
		DateTime() = default;

		/**
		*	Default \e Value constructor.
		*
		*	\param[in] _second	second values.
		*	\param[in] _minute	minute values.
		*	\param[in] _hour	hour values.
		*	\param[in] _day		day values.
		*	\param[in] _month	month values.
		*	\param[in] _year	year values.
		*	\param[in] _weekday	weekday values.
		*/
		DateTime(uint8_t _second,
			uint8_t _minute = 0u,
			uint8_t _hour = 0u,
			uint8_t _day = 0u,
			uint8_t _month = 0u,
			uint16_t _year = 0u,
			uint8_t _weekday = 0u
		) noexcept;

		/**
		*	Value constructor from tm struct.
		*
		*	\param[in] _time	tm values.
		*/
		DateTime(const struct tm& _time) noexcept;

//}

//{ Equals

		bool Equals(const DateTime& _other) const noexcept;

		bool operator==(const DateTime& _rhs) const noexcept;

		bool operator!=(const DateTime& _rhs) const noexcept;

//}

		/**
		*	\brief Get the current local date time.
		*
		*	\return DateTime.
		*/
		static DateTime Now() noexcept;

		/**
		*	\brief Get the current date time at Greenwich.
		*
		*	\return DateTime.
		*/
		static DateTime GMNow() noexcept;


		/**
		*	\brief Query file date time stats at path.
		*
		*	\param[in] _path	File path.
		*
		*	\return DateTime stats of the file at path.
		*/
		static DateTime FileStats(const std::string& _path);
	};


	/**
	*	\brief Convert DtaeTime to string with date-time format.
	* 
	*	\<month\>.\<day\>.\<year\>-\<hour\>h\<minute\>m\<second\>s
	*	Ex: 2/27/2021 at 12:07:43	=> "2.27.2021-12h07m43s"
	*
	*	\return this as a string.
	*/
	std::string ToString(const DateTime& _date);
}

#endif // GUARD
