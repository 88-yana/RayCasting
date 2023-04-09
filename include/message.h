/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:50:19 by hyanagim          #+#    #+#             */
/*   Updated: 2023/04/09 23:37:29 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

/***** Game messages ******/
# define MSG_EXIT_GAME "See you, please play again."

/***** Error messages (external)*****/
# define ERR_ARGS "Invalid arguments."
# define ERR_FILE_NAME "Invalid filename."
# define ERR_FILE_OPEN "cannot open file."
# define ERR_MALLOC_FAILURE "malloc error."
# define ERR_INPUT_FILE "file format error."
# define ERR_MAP "map format error."
# define ERR_MAP_SIZE "map's size is too big."

/***** Error messages (internal)*****/
/** 以下はユーザー操作ではなく、実装ミスにより生じるエラー */
# define ERR_FILE_FORMAT "Invalid file format."

#endif