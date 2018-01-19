/**
 * Copyright (c) 2017, Plexteq OÜ
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LIST_H_
#define _LIST_H_

/**
 * Generic linked list structure
 */
struct list_node
{
  struct list_node *next;
};

/**
 * Definition for list callback operations
 *
 * Arguments:
 * @param 0 list node
 * @param 1 arbitrary optional pointer to pass to user callback function 
 */
typedef int (*LIST_CALLBACK)(struct list_node* node, void* uptr);

/**
 * Find node in a list
 * 
 * @param root top root node
 * @param key search key
 * @param callback callback to compare, should return 0 if matches with the @key
 *
 * @return node that matches criteria or NULL if not found
 */
struct list_node* find_node(struct list_node* root, void* key, LIST_CALLBACK callback);

/**
 * Adds element to the end of existing linked list or creates new one if @root stores NULL
 *
 * @param root pointer to top root node
 * @param node node to add
 */
void append_node(struct list_node** root, struct list_node* node);

/**
 * Allows to iterate over linked list and apply callback function to each element
 *
 * @param root pointer to top root node
 * @param callback callback to apply to each element
 * @param uptr arbitrary pointer to pass to user callback function 
 */
void iterate_list(struct list_node* root, LIST_CALLBACK callback, void* uptr);

#endif
