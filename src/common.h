#ifndef COMMON_H
#define COMMON_H

typedef enum {RIGHT, LEFT, STAY, HALT} move_t;
typedef char symbol_t;

#define ACTION(move, symbol, next) { .move=move, .symbol=symbol, .next=next }

#define CONFIG2(action0, action1) { .zero = action0, .one=action1 }

#define CONFIG1(action) { .zero = action, .one=action }

/**
 * @brief An action is an operation performed by the TM. It consists
 * in:
 * move: Where to move the head next
 * symbol: What to print back to the square we are at.
 * next: Which m_config to jump to next 
 */
typedef struct {
  move_t move;
  bool symbol;
  unsigned int next;
} action_t;

/**
 * @brief m-configuaration is what Turing called these in his original paper
 * They are essentially instructions making up a program.
 * Since we, conveniently, are working with binary numbers, we
 * store 2 actions, one for the case that the current symbol is 0
 * and another for the case when the current symbol is 1.
 */

typedef struct {
  action_t zero;
  action_t one;
} m_config_t;

static void write_action(action_t*dst, move_t move, bool symbol, int next) {
  dst->move = move; 
  dst->symbol=symbol; 
  dst->next=next;
}

static void write_inst1(m_config_t *dst, move_t move, bool symbol, int next) {
  write_action(&dst->one, move,symbol,next);
  write_action(&dst->zero, move,symbol,next);
}


#endif