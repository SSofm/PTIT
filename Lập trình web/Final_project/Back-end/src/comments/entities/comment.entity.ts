import { Entity, PrimaryGeneratedColumn, Column, ManyToOne } from 'typeorm';
import { User } from '../../users/entities/user.entity';
import { Book } from '../../books/entities/book.entity';
@Entity()
export class Comment {
  @PrimaryGeneratedColumn()
  id: number;

  @Column()
  star: number;

  @Column()
  content: string;

  @ManyToOne(() => User, (user) => user.comments, {
    eager: true,
    onDelete: 'SET NULL',
  })
  user: User;

  @ManyToOne(() => Book, (book) => book.comments, {
    onDelete: 'SET NULL',
  })
  book: Book;

  @Column({ type: 'timestamp', default: () => 'CURRENT_TIMESTAMP' })
  create_at: Date;
}
