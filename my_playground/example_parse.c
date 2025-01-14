#include <boolector.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_btor_file>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    Btor *btor;
    FILE *file;
    FILE *file_out;
    FILE *file_dump;
    // Initialize Boolector
    btor = boolector_new();

    // Open the BTOR file
    file = fopen(input_file, "r");
    file_out = fopen("parse_out.log", "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open BTOR file.\n");
        return 1;
    }

    // Parse the BTOR file
    char *error_msg;
    int status;
    int result;
    result = boolector_parse_btor(btor, file, input_file, file_out, &error_msg, &status);
    // result = boolector_parse_btor2(btor, file, input_file, file_out, &error_msg, &status);
    // result = boolector_parse_btor2(btor, file, input_file, file_out, &error_msg, &status);
    fclose(file);
    fclose(file_out);

    if (result == BOOLECTOR_PARSE_ERROR) {
        fprintf(stderr, "Error: Failed to parse BTOR file.\n");
        boolector_delete(btor);
        return 1;
    }

    // Check satisfiability
    result = boolector_sat(btor);
    if (result == BOOLECTOR_SAT) {
        printf("The formula is SAT.\n");
    } else if (result == BOOLECTOR_UNSAT) {
        printf("The formula is UNSAT.\n");
    } else {
        printf("Unknown result.\n");
    }

    file_dump = fopen("dump.btor", "w");
    boolector_dump_btor(btor, file_dump);
    fclose(file_dump);

    // Clean up
    boolector_delete(btor);
    return 0;
}