function("download_extract" folder url extension)
	file(DOWNLOAD "${url}" "${CMAKE_CURRENT_SOURCE_DIR}/${folder}.${extension}")

	execute_process(
		COMMAND "${CMAKE_COMMAND}" -E tar xzf "${folder}.${extension}"
		WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	)

	file(REMOVE "${CMAKE_CURRENT_SOURCE_DIR}/${folder}.${extension}")
endfunction("download_extract")

function("download_extract_tar" folder url)
	download_extract("${folder}" "${url}" "tar.gz")
endfunction("download_extract_tar")

function("download_extract_zip" folder url)
	download_extract("${folder}" "${url}" "zip")
endfunction("download_extract_zip")

function("add_external_tar" folder url cmake)
	if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${folder}")
		download_extract_tar("${folder}" "${url}")
	endif()
	
	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${folder}/${cmake}")
endfunction("add_external_tar")

function("add_external_zip" folder url cmake)
	if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${folder}")
		download_extract_tar("${folder}" "${url}")
	endif()
	
	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${folder}/${cmake}")
endfunction("add_external_zip")

function("download_file" file url)
	if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
		file(DOWNLOAD "${url}" "${CMAKE_CURRENT_SOURCE_DIR}/${file}")
	endif()
endfunction("download_file")