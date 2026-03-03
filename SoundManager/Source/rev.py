import struct

def p8(x):
    return struct.pack('<B', x)

def p16(x):
    return struct.pack('<H', x)

def p32(x):
    return struct.pack('<I', x)

def header(w, h, num_directives):
    magic = b"cIMG"
    version = 3
    return magic + p16(version) + p8(w) + p8(h) + p32(num_directives)

def directive_62633(y, x, h_patch, w_patch, pixel_data):
    data = p16(62633) + p8(y) + p8(x) + p8(h_patch) + p8(w_patch)
    for r, g, b, c in pixel_data:
        data += bytes([r, g, b, c])
    return data

w = 35
h = 39

blob = open("blob.bin", "rb").read()
framebuffer = []

for i in range(w * h):
    pix = blob[i*24:(i+1)*24]
    r = int[7:10].decode()
    g = int[10:13].decode()
    b = int[13:16].decode()
    c = int[16:24].decode()
    framebuffer.append((r, g, b, c))
# 3x3 patch of blank white pixels
pixel_data = [(255, 255, 255, ord('x'))] * (3*3)

data = header(w, h, 1) + directive_62633(0, 0, 3, 3, pixel_data)

with open("solve.cimg", "wb") as f:
    f.write(data)

print(len(data))