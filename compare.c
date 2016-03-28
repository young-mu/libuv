// BIO mode
void main()
{
    fd = open(path, ...);
    while (read(fd, ...) != 0) {
        write(STDOUT_FILENO, ...);
    }
    close(fd);
}
// libuv AIO mode
void main()
{
    fd = uv_fs_open(&open_req, path, ..., open_cb);
    uv_run(...);
}

void open_cb(uv_fs_t *req) {
    uv_fs_read(req->result, ..., read_cb);
}

void read_cb(uv_fs_t *req) {
    if (req->result > 0) {
        uv_fs_write(STDOUT_FILENO, ..., write_cb);
    } else if (req->result == 0) {
        uv_fs_close(open_req.result, NULL);
    }
}

void write_cb(uv_fs_t *req) {
    uv_fs_read(open_req.result, ..., read_cb);
}
