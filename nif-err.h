#ifndef NIFERR_H
#define NIFERR_H

// begin error definitions here
#define __NIFERR_MISSING_CHAPTER    NIFerror(-1); // chapter is missing or restricted
#define __NIFERR_RESERVED_ID        NIFerror(1) // uses reserved numbers for IDs
#define __NIFERR_CONFLICTING_ID     NIFerror(2) // two chapter IDS are conflicting

void NIFerror(int); // error thrower

#endif // NIFERR_H
