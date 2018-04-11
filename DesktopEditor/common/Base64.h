﻿/*
 * (c) Copyright Ascensio System SIA 2010-2018
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#ifndef _BUILD_BASE64_CROSSPLATFORM_DEFINE
#define _BUILD_BASE64_CROSSPLATFORM_DEFINE

#include <stdio.h>
#include <limits.h>
#include "Types.h"

#ifndef BASE64_USE_DYNAMIC_LIBRARY
#define BASE64_DECL_EXPORT
#else
#include "./base_export.h"
#define BASE64_DECL_EXPORT Q_DECL_EXPORT
#endif

namespace NSBase64
{
	const int B64_BASE64_FLAG_NONE		= 0;
	const int B64_BASE64_FLAG_NOPAD		= 1;
	const int B64_BASE64_FLAG_NOCRLF	= 2;

	#define _BASE64_INT_MAX				2147483647
	
    BASE64_DECL_EXPORT int Base64EncodeGetRequiredLength(int nSrcLen, DWORD dwFlags = B64_BASE64_FLAG_NONE);

    BASE64_DECL_EXPORT int Base64DecodeGetRequiredLength(int nSrcLen);

    BASE64_DECL_EXPORT int Base64Encode(const BYTE *pbSrcData, int nSrcLen, BYTE* szDest, int *pnDestLen, DWORD dwFlags = B64_BASE64_FLAG_NONE);

    BASE64_DECL_EXPORT int DecodeBase64Char(unsigned int ch);

    BASE64_DECL_EXPORT int Base64Decode(const char* szSrc, int nSrcLen, BYTE *pbDest, int *pnDestLen);
}

#endif//_BUILD_BASE64_CROSSPLATFORM_DEFINE
