/*****************************************************************
# (C) Copyright IBM Corp. 2018, 2020. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# *****************************************************************/

#include <string.h>
asm (".symver old_memcpy, memcpy@GLIBC_2.2.5");       // hook old_memcpy as memcpy@2.2.5
void *old_memcpy(void *, const void *, size_t );
void *memcpy(void *dest, const void *src, size_t n)   // then export memcpy
{
    return old_memcpy(dest, src, n);
}
