void vu1_draw_scanline(int y)
{
    dma_send(bg_buffer[y], OBJ_BUFFER_SIZE);
}