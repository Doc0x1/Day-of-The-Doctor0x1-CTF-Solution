# Original flag
flag = "flag{wH1ch_doCToR_aM_1_Th0uGH?}"

# Keys
key_stage1 = "TSX"  # Simple key for stage 1
quote = "Never be cruel. Never be cowardly. Hate is always foolish. Love is always wise. Always try to be nice, but never fail to be kind."
key_stage2 = ''.join(c for c in quote if c.isupper())  # Uppercase letters from the quote

# Stage 1 Encryption: XOR with key_stage1
intermediate_flag = [
    ord(c) ^ ord(key_stage1[i % len(key_stage1)])
    for i, c in enumerate(flag)
]

# Stage 2 Encryption: XOR with key_stage2 and add 5
final_flag = [
    ((byte ^ ord(key_stage2[i % len(key_stage2)])) + 5) & 0xFF
    for i, byte in enumerate(intermediate_flag)
]

# Output final flag as a hex array for embedding in C program
print("Final Encrypted Flag:", ", ".join(f"0x{byte:02x}" for byte in final_flag))
