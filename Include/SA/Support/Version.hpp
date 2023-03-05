// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_SUPPORT_VERSION_GUARD
#define SAPPHIRE_SUPPORT_VERSION_GUARD

/**
*	\file Version.hpp
*
*	\brief \b Version definition file.
*
*	Define version preprocessors.
*	Version follows the norm Major.Minor.Patch.
*
*	\ingroup Support
*	\{
*/


/**
*	\brief create version number from major, minor and patch.
*
*	\param[in] _major	Major version.
*	\param[in] _minor	Minor version.
*	\param[in] _patch	Patch version.
*/
#define SA_MAKE_VERSION(_major, _minor, _patch) (_major * 10000 + _minor * 100 + _patch)


/** \} */

#endif // GUARD
