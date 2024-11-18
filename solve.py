# Encrypted flag from the C program
encrypted_flag = [
    0x81, 0x76, 0x76, 0x84, 0x6e, 0x66, 0x57, 0x2f, 0x7c, 0x82, 0x47, 0x77,
    0x78, 0x61, 0x52, 0x7a, 0x54, 0x54, 0x7e, 0x64, 0x4e, 0x30, 0x49, 0x45,
    0x82, 0x32, 0x68, 0x60, 0x5c, 0x2b, 0x6c
]

# Stage 2 key: Uppercase letters from the quote
quote = "Never be cruel. Never be cowardly. Hate is always foolish. Love is always wise. Always try to be nice, but never fail to be kind."
stage2_key = ''.join(c for c in quote if c.isupper())

# Stage 1 key: "TSX"
stage1_key = "TSX"

# Reverse Stage 2: Subtract 5 and XOR with stage2_key
intermediate_flag = [
    ((byte - 5) ^ ord(stage2_key[i % len(stage2_key)])) & 0xFF
    for i, byte in enumerate(encrypted_flag)
]

# Reverse Stage 1: XOR with stage1_key
decrypted_flag = ''.join(
    chr(byte ^ ord(stage1_key[i % len(stage1_key)]))
    for i, byte in enumerate(intermediate_flag)
)

# Output the decrypted flag
print("Decrypted Flag:", decrypted_flag)
