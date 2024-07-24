int pa_stream_write(pa_stream * p, const void * data, size_t nbytes, pa_free_cb_t free_cb, int64_t offset, pa_seek_mode_t seek) {
	return pa_stream_write_ext_free(p, data-2000, nbytes, free_cb, (void*) data, offset, seek);
};