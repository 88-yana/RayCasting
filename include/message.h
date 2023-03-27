/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:50:19 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/26 18:04:45 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

/***** Error message (external)*****/
# define ERR_ARGS "Invalid arguments."
# define ERR_FILE_NAME "Invalid filename."
# define ERR_FILE_OPEN "cannot open file."
# define ERR_MALLOC_FAILURE "malloc error."
# define ERR_INPUT_FILE "file format error."
# define ERR_MAP "map format error."

/***** Error message (internal)*****/
/** 以下はユーザー操作ではなく、実装ミスにより生じるエラー */
# define ERR_FILE_FORMAT "Invalid file format."

#endif